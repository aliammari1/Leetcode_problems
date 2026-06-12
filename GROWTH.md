# GROWTH.md — distribution kit for `Leetcode_problems`

Internal, not part of the published docs. Everything here needs **your GitHub /
Reddit account** to execute. The repo content (README hook, mkdocs site, lessons
index, SEO titles, cross-links) is already done on `feat/upgrade`.

The unique wedge: **this archive keeps the real failed submissions** (Wrong
Answer / TLE / Runtime Error / Compile Error) next to each accepted solution.
Every clean-solutions repo competes on count; this one competes on *honesty +
the lesson from each mistake*. Lean on that everywhere.

---

## 1. Repo "About" (GitHub → repo → ⚙ Edit)

> 173 LeetCode problems solved in C++/Java/SQL — kept WITH my real Wrong-Answer
> & TLE submissions and the lesson from each. Searchable docs site + per-problem
> verdict history.

(Keep it under 350 chars; lead with the wedge, not the count.)

## 2. Topics (GitHub → repo → ⚙ next to About → add up to 20)

Paste these 8 exact-match topics (high-intent search terms, all valid GitHub
topic slugs):

```
leetcode
leetcode-solutions
algorithms
sql
oracle-sql
interview-prep
coding-interview
data-structures
```

Optional extras if you want more surface: `cpp`, `competitive-programming`,
`leetcode-cpp`, `dsa`.

## 3. Reddit — r/leetcode (the single best organic launch)

Personal-story headlines pull ~3× the upvotes of "I made X". Post Tue–Thu,
13:00–16:00 UTC. Build a little karma/comment first so it isn't your first post.

**Title:**
> I made my LeetCode repo public WITH all my failed submissions

**Body (paste, tweak the voice):**
> Most solution repos only show the clean accepted answer. I kept the opposite:
> every Wrong Answer, TLE, Runtime Error and Compile Error I submitted *before*
> getting each problem accepted — 173 problems, 542 submission files, each
> timestamped, in C++/Java/SQL.
>
> There's a searchable docs site where each problem page shows the full verdict
> history (Accepted → WA → TLE → RE) with the code for each attempt in language
> tabs, plus a "Lessons / common mistakes" index of the 89 problems I did *not*
> get on the first try.
>
> Browse: https://leetcode-problems.pages.dev
> Repo: https://github.com/aliammari1/Leetcode_problems
>
> Honestly the failed attempts taught me more than the accepted ones. Curious if
> others keep their wrong submissions or delete them.

- Reply to the first comments within the hour; that drives the ranking.
- Cross-post variants: r/cscareerquestions (only if it fits a discussion),
  r/programming (riskier — needs the "why" framing, no naked self-promo).

## 4. Awesome-list / directory submission PRs

Compounding passive faucet. Open one PR per list; lead with the wedge line.

**`awesome-leetcode-resources`** (e.g. ashishps1/awesome-leetcode-resources) —
under a "Solutions / Repositories" section:

```markdown
- [aliammari1/Leetcode_problems](https://github.com/aliammari1/Leetcode_problems) — 173 problems in C++/Java/SQL kept WITH their real Wrong-Answer/TLE submission history and a per-problem "what went wrong" lesson; searchable mkdocs site.
```

**`awesome-competitive-programming`** (e.g. lnishan/awesome-competitive-programming) —
under "Solutions / Practice":

```markdown
- [aliammari1/Leetcode_problems](https://github.com/aliammari1/Leetcode_problems) — A LeetCode solution archive that preserves every failed submission (Wrong Answer, TLE, Runtime Error) before each accept, across C++/Java/Oracle-SQL, with a searchable docs site.
```

Read each list's CONTRIBUTING + run its linter (often `awesome-lint`) before the
PR. Match the existing entry style exactly or it gets bounced.

## 5. SEO (already shipped — what's working for you)

- Per-problem docs page `<title>` = exact `"<#>. <Problem> — Solution"` (the
  literal phrase people search). 173 pages = 173 long-tail landing pages.
- `Lessons / common mistakes` index page targets the "common leetcode mistakes /
  why is my submission wrong" intent that clean repos don't rank for.
- Cross-link footer on every page → HackerRank archive + profile hub (internal
  backlinks raise the whole portfolio's discoverability).
- Keep commits flowing (freshness signal) and re-run
  `python scripts/generate_progress.py --docs` whenever you add problems.

## 6. The MCP angle (Wave 2 — build later, mention now)

`leetcode-solutions-mcp`: bundle this archive (problems + wrong-answer history)
as an **offline, no-auth MCP server** — rivals need a session cookie. Pitch:
*"the MCP that remembers what NOT to do."* When built: list on
punkpeye/awesome-mcp-servers, mcpmarket.com, and the official MCP registry, and
back-link it from this README. The README already teases it so the audience is
primed.

---

### Execution order (highest ROI first)

1. Set **About + 8 topics** (5 min, compounding SEO).
2. Post to **r/leetcode** with the story title (the spike).
3. Open the **awesome-leetcode-resources** + **awesome-competitive-programming**
   PRs (passive forever).
4. Build + list the **MCP** (Wave 2, highest ceiling).
