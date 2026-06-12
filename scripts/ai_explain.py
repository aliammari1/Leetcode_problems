#!/usr/bin/env python3
"""Generate per-solution AI explanations with Claude.

For each Accepted solution this writes an ``EXPLANATION.md`` next to it covering:

1. the approach and intuition,
2. time / space complexity,
3. **a diff/explanation versus the sibling Wrong-Answer / Runtime-Error / TLE
   attempts for the same problem** — what the earlier submission got wrong and
   how the accepted one fixes it. That comparison against the real failed
   attempts is the unique hook of this archive.

Optionally (``--tag``) it also emits a one-line difficulty + pattern tag block,
which the docs generator can surface as tags.

The output feeds the mkdocs page generator (`generate_progress.py --docs`),
which embeds any `EXPLANATION.md` it finds on the problem page.

Gated on ``ANTHROPIC_API_KEY``: if the key is unset the script prints a notice
and exits 0, so the workflow is a no-op on forks/PRs without the secret. Uses
the official Anthropic Python SDK (``pip install anthropic``).

Usage::

    python scripts/ai_explain.py                  # all Accepted lacking EXPLANATION.md
    python scripts/ai_explain.py --slug two-sum    # one problem
    python scripts/ai_explain.py --force --limit 20
    python scripts/ai_explain.py --model claude-sonnet-4-6
"""

from __future__ import annotations

import argparse
import os
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
SOLUTIONS = ROOT / "solutions"
DEFAULT_MODEL = "claude-sonnet-4-6"

SYSTEM_PROMPT = (
    "You are a precise competitive-programming reviewer. You write tight, "
    "technically accurate explanations of LeetCode solutions for a "
    "documentation site. Use Markdown. Do not restate the full problem; assume "
    "the reader can follow the linked problem. Be concrete about complexity and "
    "about the specific bug in any failed attempt."
)


def read_solution(d: Path) -> str | None:
    for sol in sorted(d.glob("Solution.*")):
        if sol.is_file():
            return sol.read_text(encoding="utf-8", errors="replace")
    return None


def collect_attempts(slug_dir: Path) -> dict[str, list[str]]:
    """Return {verdict: [code, ...]} across all timestamp dirs for a slug."""
    out: dict[str, list[str]] = {}
    for verdict_dir in sorted(p for p in slug_dir.iterdir() if p.is_dir()):
        for ts_dir in sorted(p for p in verdict_dir.iterdir() if p.is_dir()):
            code = read_solution(ts_dir)
            if code:
                out.setdefault(verdict_dir.name, []).append(code)
    return out


def build_prompt(slug: str, accepted_code: str, attempts: dict[str, list[str]], tag: bool) -> str:
    parts = [
        f"Problem: https://leetcode.com/problems/{slug}/",
        "",
        "ACCEPTED solution:",
        "```",
        accepted_code.strip(),
        "```",
    ]
    failed = {v: c for v, c in attempts.items() if v != "Accepted"}
    if failed:
        parts += ["", "Earlier FAILED attempts on the same problem:"]
        for verdict, codes in failed.items():
            for code in codes[:2]:  # cap to keep the prompt bounded
                parts += [f"", f"[{verdict}]", "```", code.strip(), "```"]
    parts += [
        "",
        "Write EXPLANATION.md with these sections:",
        "## Approach — the intuition and the algorithm in a few sentences.",
        "## Complexity — time and space, with a one-line justification.",
    ]
    if failed:
        parts.append(
            "## What the earlier attempts got wrong — for each failed verdict "
            "above, name the specific bug (off-by-one, wrong data structure, "
            "missing edge case, etc.) and how the accepted version fixes it."
        )
    else:
        parts.append(
            "## Notes — any edge cases or pitfalls worth flagging (there are no "
            "recorded failed attempts for this problem)."
        )
    if tag:
        parts.append(
            "Finally add a line exactly like `Tags: difficulty=<easy|medium|hard>, "
            "pattern=<one or two patterns>` based on the solution."
        )
    return "\n".join(parts)


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument("--model", default=os.environ.get("AI_MODEL", DEFAULT_MODEL))
    ap.add_argument("--slug", help="only this slug")
    ap.add_argument("--limit", type=int, default=0, help="cap number of slugs processed")
    ap.add_argument("--force", action="store_true", help="overwrite existing EXPLANATION.md")
    ap.add_argument("--tag", action="store_true", help="also emit difficulty/pattern tags")
    args = ap.parse_args()

    api_key = os.environ.get("ANTHROPIC_API_KEY")
    if not api_key:
        print("ANTHROPIC_API_KEY not set — skipping AI explanations (no-op).")
        return 0

    try:
        import anthropic
    except ImportError:
        print("::error::`anthropic` package not installed (pip install anthropic).", file=sys.stderr)
        return 2

    client = anthropic.Anthropic(api_key=api_key)

    slug_dirs = sorted(p for p in SOLUTIONS.iterdir() if p.is_dir())
    if args.slug:
        slug_dirs = [p for p in slug_dirs if p.name == args.slug]

    processed = 0
    for slug_dir in slug_dirs:
        if args.limit and processed >= args.limit:
            break
        accepted_dir = slug_dir / "Accepted"
        if not accepted_dir.is_dir():
            continue
        # Pick the most recent accepted attempt that has a solution file.
        accepted_code = None
        target_dir = None
        for ts_dir in sorted((p for p in accepted_dir.iterdir() if p.is_dir()), reverse=True):
            code = read_solution(ts_dir)
            if code:
                accepted_code, target_dir = code, ts_dir
                break
        if not accepted_code or target_dir is None:
            continue
        out_path = target_dir / "EXPLANATION.md"
        if out_path.exists() and not args.force:
            continue

        attempts = collect_attempts(slug_dir)
        prompt = build_prompt(slug_dir.name, accepted_code, attempts, args.tag)

        try:
            # Adaptive thinking + streaming per Claude API guidance.
            with client.messages.stream(
                model=args.model,
                max_tokens=2000,
                system=SYSTEM_PROMPT,
                thinking={"type": "adaptive"},
                messages=[{"role": "user", "content": prompt}],
            ) as stream:
                msg = stream.get_final_message()
        except Exception as exc:  # noqa: BLE001 - surface and continue
            print(f"::warning::{slug_dir.name}: API error: {exc}", file=sys.stderr)
            continue

        text = "".join(b.text for b in msg.content if b.type == "text").strip()
        if not text:
            print(f"::warning::{slug_dir.name}: empty response", file=sys.stderr)
            continue

        header = (
            f"<!-- Generated by scripts/ai_explain.py using {args.model}. "
            "Review before trusting. -->\n\n"
        )
        out_path.write_text(header + text + "\n", encoding="utf-8")
        print(f"wrote {out_path.relative_to(ROOT)}")
        processed += 1

    print(f"done: {processed} explanation(s) generated.")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
