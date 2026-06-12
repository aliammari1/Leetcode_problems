#!/usr/bin/env python3
"""Preamble-injection C++ syntax gate.

The saved snippets are bare LeetCode editor bodies: a `class Solution { ... }`
(or a free function) with **no `#include` and no `using namespace std;`**. A
plain `g++ Solution.cpp` would fail to even parse `string`/`vector`/`reverse`,
so the repo's old CI "compiled" nothing and passed via `|| echo`.

This gate fixes that. For each Accepted `Solution.cpp` it writes a temp file:

    #include <bits/stdc++.h>
    using namespace std;
    <original snippet>

then runs `g++ -std=c++20 -fsyntax-only -Wall` and fails on real compiler
errors (warnings do not fail the build). It is a *syntax* gate — it does not
link or run, because these are method bodies with no `main()` and no judge
harness.

Only Accepted snippets are checked by default: Wrong-Answer / Runtime-Error /
TLE attempts are kept deliberately as part of the submission history and may
legitimately not even parse (Compile Error verdicts certainly won't).

All filesystem access uses pathlib, so the spaces+commas in verdict/timestamp
directory names need no shell quoting here. (The README/CI shell one-liners that
glob these paths quote them; this script is the portable path.)

Usage::

    python scripts/compile_check.py                 # all Accepted .cpp
    python scripts/compile_check.py --all-verdicts   # every .cpp (expect failures)
    python scripts/compile_check.py --cxx g++-13 --std c++20
"""

from __future__ import annotations

import argparse
import shutil
import subprocess
import sys
import tempfile
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
SOLUTIONS = ROOT / "solutions"
PREAMBLE = "#include <bits/stdc++.h>\nusing namespace std;\n"


def iter_cpp(all_verdicts: bool):
    """Yield Solution.cpp paths. By default only those under an Accepted dir."""
    for slug_dir in sorted(p for p in SOLUTIONS.iterdir() if p.is_dir()):
        for verdict_dir in sorted(p for p in slug_dir.iterdir() if p.is_dir()):
            if not all_verdicts and verdict_dir.name != "Accepted":
                continue
            for sol in verdict_dir.rglob("Solution.cpp"):
                yield sol


def check_one(cxx: str, std: str, src: Path) -> tuple[bool, str]:
    body = src.read_text(encoding="utf-8", errors="replace")
    with tempfile.NamedTemporaryFile(
        "w", suffix=".cpp", delete=False, encoding="utf-8"
    ) as tmp:
        tmp.write(PREAMBLE)
        tmp.write(body)
        tmp_path = Path(tmp.name)
    try:
        proc = subprocess.run(
            [cxx, f"-std={std}", "-fsyntax-only", "-Wall", str(tmp_path)],
            capture_output=True,
            text=True,
        )
        return proc.returncode == 0, proc.stderr
    finally:
        tmp_path.unlink(missing_ok=True)


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument("--cxx", default="g++", help="C++ compiler (default: g++)")
    ap.add_argument("--std", default="c++20", help="C++ standard (default: c++20)")
    ap.add_argument(
        "--all-verdicts",
        action="store_true",
        help="check every Solution.cpp, not just Accepted (expect failures)",
    )
    args = ap.parse_args()

    if shutil.which(args.cxx) is None:
        print(
            f"::error::compiler '{args.cxx}' not found on PATH; cannot run the "
            "C++ syntax gate.",
            file=sys.stderr,
        )
        return 2

    failures: list[tuple[Path, str]] = []
    total = 0
    for src in iter_cpp(args.all_verdicts):
        total += 1
        ok, stderr = check_one(args.cxx, args.std, src)
        rel = src.relative_to(ROOT)
        if ok:
            print(f"PASS  {rel}")
        else:
            print(f"FAIL  {rel}")
            failures.append((rel, stderr))

    print(f"\nChecked {total} file(s); {len(failures)} failed.")
    if failures:
        print("\n--- failures ---", file=sys.stderr)
        for rel, stderr in failures:
            print(f"\n### {rel}", file=sys.stderr)
            print(stderr.strip(), file=sys.stderr)
        return 1
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
