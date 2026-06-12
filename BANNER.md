# Banner / social preview — TODO

The repository banner and GitHub social-preview image are **not yet generated**.
This file is the brief for producing them.

## Direction

**Pattern-grid, dark.** A dense grid evoking a LeetCode problem matrix /
submission heatmap — small monochrome tiles on a near-black background, a few
accent tiles in amber/green marking "Accepted", subtle muted reds/oranges for
the Wrong-Answer / Runtime-Error / TLE attempts that this archive uniquely
preserves. Mono/technical typeface. The hook to convey: *real submission
history, including the wrong attempts*.

## Deliverables

- `assets/banner.png` — wide README hero (referenced as a TODO comment at the
  top of `README.md`).
- `assets/social-preview.png` — **1280×640**, set via GitHub →
  Settings → Social preview.

## How to generate

Use the `brandkit` Claude skill for the identity board + 1280×640 social card,
and `imagegen-frontend-web` for the wide README hero. Commit the results as
local PNG/SVG under `assets/` (never hot-link, to avoid 404 / rate-limit).

Once committed, uncomment the banner line at the top of `README.md`.
