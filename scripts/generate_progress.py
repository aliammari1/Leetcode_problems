#!/usr/bin/env python3
"""Single source of truth for this archive's statistics and docs.

Walks ``solutions/<slug>/<Verdict>/<timestamp>/Solution.<ext>``, reconciling
the two numbers the README used to contradict each other on:

* **unique slugs**  -- one directory per LeetCode problem
* **submission files** -- every saved attempt, across verdicts/timestamps

It is the only place these counts are computed. From the parsed model it
regenerates:

* ``docs/progress.json``       -- machine-readable stats (feeds dynamic badges)
* the ``<!-- PROGRESS:START -->`` block in ``README.md``
* ``docs/`` mkdocs-material pages (one per slug + indexes), when ``--docs``

Layout note: verdict and timestamp directory names contain spaces **and**
commas (e.g. ``Wrong Answer/8-8-2023, 12_20_23 AM``). Everything here uses
``pathlib`` so no shell quoting is involved; the CI globs that *do* touch the
shell quote every path (see ``.github/workflows``).

Usage::

    python scripts/generate_progress.py            # regenerate stats + README
    python scripts/generate_progress.py --docs      # also (re)build docs/ pages
    python scripts/generate_progress.py --check      # exit 1 if anything is stale
"""

from __future__ import annotations

import argparse
import json
import re
import sys
from collections import Counter, defaultdict
from dataclasses import dataclass, field
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
SOLUTIONS = ROOT / "solutions"
DOCS = ROOT / "docs"
README = ROOT / "README.md"
PROGRESS_JSON = DOCS / "progress.json"
NUMBERS_JSON = Path(__file__).resolve().parent / "problem_numbers.json"


def load_numbers() -> dict[str, int]:
    """Slug -> canonical LeetCode problem number (for exact-match SEO titles).

    Optional file; missing slugs simply omit the number prefix.
    """
    if not NUMBERS_JSON.is_file():
        return {}
    raw = json.loads(NUMBERS_JSON.read_text(encoding="utf-8"))
    return {k: v for k, v in raw.items() if not k.startswith("_")}


NUMBERS = load_numbers()

# Maps file extension -> (display language, mkdocs content-tab fence language).
EXT_LANG = {
    ".cpp": ("C++", "cpp"),
    ".java": ("Java", "java"),
    ".oraclesql": ("Oracle SQL", "sql"),
    ".mysql": ("MySQL", "sql"),
}

# First-line metadata hook present in every solution file, e.g.
#   // https://leetcode.com/problems/two-sum
SLUG_RE = re.compile(r"leetcode\.com/problems/([a-z0-9-]+)", re.IGNORECASE)

VERDICT_ORDER = [
    "Accepted",
    "Wrong Answer",
    "Time Limit Exceeded",
    "Runtime Error",
    "Compile Error",
]

PROGRESS_START = "<!-- PROGRESS:START -->"
PROGRESS_END = "<!-- PROGRESS:END -->"


@dataclass
class Submission:
    slug: str
    verdict: str
    timestamp: str
    ext: str
    path: Path

    @property
    def language(self) -> str:
        return EXT_LANG.get(self.ext, (self.ext.lstrip("."), "text"))[0]


@dataclass
class Problem:
    slug: str
    submissions: list[Submission] = field(default_factory=list)

    @property
    def url(self) -> str:
        return f"https://leetcode.com/problems/{self.slug}/"

    @property
    def title(self) -> str:
        return self.slug.replace("-", " ").title()

    @property
    def number(self) -> int | None:
        return NUMBERS.get(self.slug)

    @property
    def seo_title(self) -> str:
        """Exact-match page title for search: '<#>. <Problem> — Solution'.

        Falls back to '<Problem> — Solution' when the number is unknown.
        """
        if self.number is not None:
            return f"{self.number}. {self.title} — Solution"
        return f"{self.title} — Solution"

    @property
    def accepted(self) -> bool:
        return any(s.verdict == "Accepted" for s in self.submissions)

    @property
    def languages(self) -> list[str]:
        seen: list[str] = []
        for s in self.submissions:
            if s.language not in seen:
                seen.append(s.language)
        return seen


def first_line_slug(path: Path) -> str | None:
    """Return the slug from the file's first-line comment, if present."""
    try:
        with path.open("r", encoding="utf-8", errors="replace") as fh:
            for _ in range(5):  # slug is on line 1, but tolerate a stray BOM/blank
                line = fh.readline()
                if not line:
                    break
                m = SLUG_RE.search(line)
                if m:
                    return m.group(1).lower()
    except OSError:
        return None
    return None


def scan() -> dict[str, Problem]:
    """Walk solutions/ and build the slug -> Problem map.

    Slug is taken from the first-line comment where available and falls back to
    the directory name (they agree across the whole archive today, but the
    comment is the authoritative metadata hook the README documents).
    """
    problems: dict[str, Problem] = {}
    if not SOLUTIONS.is_dir():
        return problems

    for slug_dir in sorted(p for p in SOLUTIONS.iterdir() if p.is_dir()):
        dir_slug = slug_dir.name
        for verdict_dir in sorted(p for p in slug_dir.iterdir() if p.is_dir()):
            verdict = verdict_dir.name
            for ts_dir in sorted(p for p in verdict_dir.iterdir() if p.is_dir()):
                timestamp = ts_dir.name
                for sol in sorted(ts_dir.iterdir()):
                    if not sol.is_file() or sol.suffix not in EXT_LANG:
                        continue
                    slug = first_line_slug(sol) or dir_slug
                    problems.setdefault(slug, Problem(slug))
                    problems[slug].submissions.append(
                        Submission(slug, verdict, timestamp, sol.suffix, sol)
                    )
    return problems


def compute_stats(problems: dict[str, Problem]) -> dict:
    lang_files: Counter[str] = Counter()
    verdict_files: Counter[str] = Counter()
    lang_slugs: dict[str, set[str]] = defaultdict(set)
    total_files = 0
    accepted_slugs = 0

    for slug, prob in problems.items():
        if prob.accepted:
            accepted_slugs += 1
        for s in prob.submissions:
            total_files += 1
            lang_files[s.language] += 1
            verdict_files[s.verdict] += 1
            lang_slugs[s.language].add(slug)

    unique_slugs = len(problems)
    languages = []
    for lang in ("C++", "Java", "Oracle SQL", "MySQL"):
        if lang_files.get(lang):
            languages.append(
                {
                    "language": lang,
                    "files": lang_files[lang],
                    "slugs": len(lang_slugs[lang]),
                    "pct_files": round(100 * lang_files[lang] / total_files, 1)
                    if total_files
                    else 0.0,
                }
            )

    verdicts = [
        {"verdict": v, "files": verdict_files[v]}
        for v in VERDICT_ORDER
        if verdict_files.get(v)
    ]

    accepted_pct = round(100 * accepted_slugs / unique_slugs, 1) if unique_slugs else 0.0

    return {
        "unique_slugs": unique_slugs,
        "total_files": total_files,
        "accepted_slugs": accepted_slugs,
        "accepted_pct": accepted_pct,
        "languages": languages,
        "verdicts": verdicts,
    }


def progress_json(stats: dict) -> dict:
    """Shape for docs/progress.json -- also a shields.io endpoint badge source."""
    return {
        "schemaVersion": 1,
        "label": "solved",
        "message": f"{stats['unique_slugs']} problems",
        "color": "brightgreen",
        "stats": stats,
    }


def render_progress_block(stats: dict) -> str:
    lines = [
        PROGRESS_START,
        "",
        f"- **Unique problems (slugs):** {stats['unique_slugs']}",
        f"- **Total submission files:** {stats['total_files']} "
        "(every saved attempt across verdicts and timestamps)",
        f"- **Accepted problems:** {stats['accepted_slugs']} "
        f"({stats['accepted_pct']}% of unique problems)",
        "",
        "### Language coverage",
        "",
        "| Language | Files | Problems | % of files |",
        "|----------|-------|----------|-----------|",
    ]
    for lang in stats["languages"]:
        lines.append(
            f"| {lang['language']} | {lang['files']} | {lang['slugs']} | {lang['pct_files']}% |"
        )
    lines.append(
        f"| **Total** | **{stats['total_files']}** | **{stats['unique_slugs']}** | **100%** |"
    )
    lines += ["", "### Submission verdicts", "", "| Verdict | Files |", "|---------|-------|"]
    for v in stats["verdicts"]:
        lines.append(f"| {v['verdict']} | {v['files']} |")
    lines += [
        "",
        f"*Generated by `scripts/generate_progress.py`. Do not edit this block by hand.*",
        "",
        PROGRESS_END,
    ]
    return "\n".join(lines)


def update_readme(stats: dict) -> str:
    text = README.read_text(encoding="utf-8")
    block = render_progress_block(stats)
    if PROGRESS_START in text and PROGRESS_END in text:
        new = re.sub(
            re.escape(PROGRESS_START) + r".*?" + re.escape(PROGRESS_END),
            block,
            text,
            flags=re.DOTALL,
        )
    else:
        # Insert the block right after the "## Progress Statistics" heading.
        marker = "## 📊 Progress Statistics"
        if marker in text:
            head, tail = text.split(marker, 1)
            # Drop the old static table up to the next "##" heading.
            rest = re.sub(r".*?(\n## )", r"\1", tail, count=1, flags=re.DOTALL)
            new = f"{head}{marker}\n\n{block}\n{rest}"
        else:
            new = text + "\n\n## 📊 Progress Statistics\n\n" + block + "\n"
    return new


# --------------------------------------------------------------------------- #
# Docs generation (mkdocs-material)
# --------------------------------------------------------------------------- #

def slugify_lang(lang: str) -> str:
    return lang.lower().replace("+", "p").replace(" ", "-")


def build_docs(problems: dict[str, Problem], stats: dict) -> None:
    pages = DOCS / "problems"
    pages.mkdir(parents=True, exist_ok=True)
    # Clear stale generated pages.
    for old in pages.glob("*.md"):
        old.unlink()

    for slug, prob in sorted(problems.items()):
        write_problem_page(pages / f"{slug}.md", prob)

    write_problems_index(pages / "index.md", problems)
    write_tags_index(DOCS / "tags.md", problems)
    write_lessons_index(DOCS / "lessons.md", problems)
    write_docs_home(DOCS / "index.md", stats, problems)


# Verdicts that are "wrong attempts" worth a lesson callout.
WRONG_VERDICTS = ("Wrong Answer", "Time Limit Exceeded", "Runtime Error", "Compile Error")

# Cross-link footer (Related projects + profile hub) appended to every page.
RELATED_FOOTER = "\n".join(
    [
        "---",
        "",
        "**Related:** "
        "[HackerRank solution archive](https://github.com/aliammari1/Hackerrank_problems) · "
        "[All my projects (profile hub)](https://github.com/aliammari1) · "
        "[LeetCode profile](https://leetcode.com/aliammari1/)",
    ]
)


def write_problem_page(path: Path, prob: Problem) -> None:
    lines = [
        f"# {prob.seo_title}",
        "",
        f"[:material-open-in-new: Open on LeetCode]({prob.url}){{ .md-button }}",
        "",
    ]
    # AI explanation, if the AI workflow produced one for any accepted attempt.
    for s in prob.submissions:
        expl = s.path.parent / "EXPLANATION.md"
        if s.verdict == "Accepted" and expl.is_file():
            lines += ["## Explanation", "", expl.read_text(encoding="utf-8").strip(), ""]
            break

    lines += ["## Verdict history", "", "| Verdict | Language | Submitted |", "|---------|----------|-----------|"]
    for s in sorted(prob.submissions, key=lambda x: (VERDICT_ORDER.index(x.verdict) if x.verdict in VERDICT_ORDER else 99, x.timestamp)):
        lines.append(f"| {s.verdict} | {s.language} | {s.timestamp} |")
    lines.append("")

    # Group solutions into content tabs by language, accepted first.
    lines += ["## Solutions", ""]
    by_lang: dict[str, list[Submission]] = defaultdict(list)
    for s in prob.submissions:
        by_lang[s.language].append(s)
    for lang, subs in by_lang.items():
        fence = EXT_LANG.get(subs[0].ext, ("", "text"))[1]
        subs_sorted = sorted(subs, key=lambda x: (x.verdict != "Accepted", x.timestamp))
        lines.append(f'=== "{lang}"')
        lines.append("")
        for s in subs_sorted:
            code = s.path.read_text(encoding="utf-8", errors="replace").rstrip()
            lines.append(f"    **{s.verdict}** — {s.timestamp}")
            lines.append("")
            lines.append(f"    ```{fence}")
            for codeline in code.splitlines():
                lines.append(f"    {codeline}")
            lines.append("    ```")
            lines.append("")
    lines.append(RELATED_FOOTER)
    lines.append("")
    path.write_text("\n".join(lines) + "\n", encoding="utf-8")


def write_problems_index(path: Path, problems: dict[str, Problem]) -> None:
    lines = ["# All Problems", "", "| # | Problem | Status | Languages |", "|---|---------|--------|-----------|"]
    for slug, prob in sorted(problems.items()):
        status = "✅ Accepted" if prob.accepted else "⏳ Attempted"
        langs = ", ".join(prob.languages)
        num = str(prob.number) if prob.number is not None else "—"
        lines.append(f"| {num} | [{prob.title}]({slug}.md) | {status} | {langs} |")
    lines.append("")
    path.write_text("\n".join(lines) + "\n", encoding="utf-8")


def write_lessons_index(path: Path, problems: dict[str, Problem]) -> None:
    """Index of problems that have real failed attempts before the accept.

    This is the archive's signature page: the slugs where there is a documented
    Wrong Answer / TLE / Runtime Error / Compile Error to learn from.
    """
    rows: list[tuple[Problem, Counter[str]]] = []
    for prob in problems.values():
        wrong: Counter[str] = Counter()
        for s in prob.submissions:
            if s.verdict in WRONG_VERDICTS:
                wrong[s.verdict] += 1
        if wrong:
            rows.append((prob, wrong))

    rows.sort(key=lambda r: (-sum(r[1].values()), r[0].slug))
    total_wrong = sum(sum(w.values()) for _, w in rows)

    lines = [
        "# Lessons / common mistakes",
        "",
        "The point of this archive: **every problem below was *not* solved on the",
        "first try.** These pages keep the failed submissions — Wrong Answer, Time",
        "Limit Exceeded, Runtime Error, Compile Error — next to the accepted one, so",
        "you can read *what went wrong and why* instead of only a clean final answer.",
        "",
        f"- **Problems with at least one failed attempt:** {len(rows)}",
        f"- **Total failed submissions preserved:** {total_wrong}",
        "",
        "| # | Problem | Failed attempts (by verdict) |",
        "|---|---------|------------------------------|",
    ]
    for prob, wrong in rows:
        num = str(prob.number) if prob.number is not None else "—"
        detail = ", ".join(f"{v}: {wrong[v]}" for v in VERDICT_ORDER if wrong.get(v))
        lines.append(f"| {num} | [{prob.title}](problems/{prob.slug}.md) | {detail} |")
    lines.append("")
    path.write_text("\n".join(lines) + "\n", encoding="utf-8")


def write_tags_index(path: Path, problems: dict[str, Problem]) -> None:
    """Index by language; AI pattern/difficulty tags slot in here when present."""
    by_lang: dict[str, list[Problem]] = defaultdict(list)
    for prob in problems.values():
        for lang in prob.languages:
            by_lang[lang].append(prob)
    lines = ["# Index by Language", ""]
    for lang in sorted(by_lang):
        lines.append(f"## {lang}")
        lines.append("")
        for prob in sorted(by_lang[lang], key=lambda p: p.slug):
            lines.append(f"- [{prob.title}](problems/{prob.slug}.md)")
        lines.append("")
    path.write_text("\n".join(lines) + "\n", encoding="utf-8")


def write_docs_home(path: Path, stats: dict, problems: dict[str, Problem]) -> None:
    n = stats["unique_slugs"]
    lines = [
        "# LeetCode Solutions Archive",
        "",
        "Every LeetCode problem I solved — **including my real Wrong-Answer / TLE",
        "submissions and the lesson from each.** Not a clean-solutions dump: each page",
        "keeps the failed attempts next to the accepted one so you can read the",
        "*progression*, not just the final answer.",
        "",
        f"[:material-magnify: Browse all {n} problems (searchable)]"
        "(problems/index.md){ .md-button .md-button--primary }",
        "[:material-lightbulb-on: Lessons / common mistakes](lessons.md){ .md-button }",
        "",
        "> Use the search box (top right) to jump straight to any problem by number or",
        "> name.",
        "",
        "## At a glance",
        "",
        f"- **Unique problems:** {stats['unique_slugs']}",
        f"- **Total submissions:** {stats['total_files']}",
        f"- **Accepted:** {stats['accepted_slugs']} ({stats['accepted_pct']}%)",
        "",
        "| Language | Files | Problems |",
        "|----------|-------|----------|",
    ]
    for lang in stats["languages"]:
        lines.append(f"| {lang['language']} | {lang['files']} | {lang['slugs']} |")
    lines += [
        "",
        "## Coming soon: the `leetcode-solutions` MCP (Wave 2)",
        "",
        "A bundled, offline **MCP server** that exposes this archive — 173 problems",
        "*with their real wrong-answer history* — to any MCP-capable assistant. No",
        "session cookie required (rivals need one). *\"The MCP that remembers what NOT",
        "to do.\"*",
        "",
        RELATED_FOOTER,
        "",
    ]
    path.write_text("\n".join(lines) + "\n", encoding="utf-8")


# --------------------------------------------------------------------------- #


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument("--docs", action="store_true", help="also (re)build docs/ pages")
    ap.add_argument(
        "--check",
        action="store_true",
        help="verify README/progress.json are up to date; exit 1 if stale",
    )
    args = ap.parse_args()

    problems = scan()
    stats = compute_stats(problems)
    pj = progress_json(stats)
    new_readme = update_readme(stats)
    pj_text = json.dumps(pj, indent=2) + "\n"

    print(
        f"slugs={stats['unique_slugs']} files={stats['total_files']} "
        f"accepted={stats['accepted_slugs']} ({stats['accepted_pct']}%)"
    )
    for lang in stats["languages"]:
        print(f"  {lang['language']:<12} files={lang['files']:<4} slugs={lang['slugs']}")

    if args.check:
        stale = []
        current_readme = README.read_text(encoding="utf-8")
        if current_readme != new_readme:
            stale.append("README.md progress block")
        if not PROGRESS_JSON.is_file() or PROGRESS_JSON.read_text(encoding="utf-8") != pj_text:
            stale.append("docs/progress.json")
        if stale:
            print("STALE (run scripts/generate_progress.py): " + ", ".join(stale), file=sys.stderr)
            return 1
        print("OK: generated artifacts are up to date.")
        return 0

    DOCS.mkdir(parents=True, exist_ok=True)
    PROGRESS_JSON.write_text(pj_text, encoding="utf-8")
    README.write_text(new_readme, encoding="utf-8")
    print(f"wrote {PROGRESS_JSON.relative_to(ROOT)} and updated README.md")

    if args.docs:
        build_docs(problems, stats)
        print(f"wrote docs/ pages for {len(problems)} problems")

    return 0


if __name__ == "__main__":
    raise SystemExit(main())
