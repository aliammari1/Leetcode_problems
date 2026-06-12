# Banner / social preview

The repository banner and GitHub social-preview image are generated from the
**single image-generation prompt** below. Run it, then commit the outputs under
`assets/` and uncomment the banner line at the top of `README.md`.

## Deliverables

- `assets/banner.png` — wide README hero (referenced by the commented-out line
  at the top of `README.md` as `assets/banner.png`).
- `assets/social-preview.png` — **1280×640**, set via GitHub → Settings →
  Social preview.

Commit the results as local PNG/SVG under `assets/` (never hot-link, to avoid
404 / rate-limit). Keep the same composition for both sizes so they read as one
identity.

## The prompt (use verbatim)

> A dark, near-black technical banner for a LeetCode solution archive. The
> background is a dense **pattern grid / submission heatmap**: small square
> monochrome tiles in a tight matrix. Most tiles are muted dark-grey;
> **accent tiles glow amber and green for "Accepted"**, with a scattering of
> **muted red / orange tiles marking the Wrong-Answer, Runtime-Error, and
> Time-Limit-Exceeded attempts** — conveying the hook *"real submission
> history, including the wrong attempts."*
>
> Overlaid on the grid, **14 labelled pattern tiles** in a clean mono/technical
> typeface, one per algorithm family: **Arrays, Two Pointers, Sliding Window,
> Binary Search, Hashing, Stack, Linked List, Trees, BFS/DFS, Divide &
> Conquer, Greedy, Dynamic Programming, Math, SQL**.
>
> A compact language strip with three marks: **C++**, **Java**, **Oracle SQL**.
>
> Bold headline text: **"173 problems · 542 submissions"**. Small subtitle:
> *"every accepted solution — and the wrong attempts before it."*
>
> Aesthetic: editorial dark-tech, high contrast, generous spacing, amber accent
> (#FFB300-ish) on near-black (#0B0B0D), no clutter, no photographic elements,
> crisp pixel-grid feel.
>
> Render two crops sharing this exact composition: a **1280×640** social card
> (`social-preview.png`) and a **wide README hero** banner (`banner.png`).

## How to generate

Use the `brandkit` Claude skill for the 1280×640 social card and
`imagegen-frontend-web` for the wide README hero, feeding both the prompt above.
