# Security Policy

This repository is an archive of personal LeetCode solutions — it ships no
running service, no dependencies that execute at runtime, and stores no secrets.
The practical security surface is the CI/automation tooling.

## Reporting

If you find a problem in the tooling (a workflow that could leak a token, a
script with a command-injection issue, etc.), please open a
[GitHub Security Advisory](https://github.com/aliammari1/Leetcode_problems/security/advisories/new)
or email the maintainer. Please do **not** open a public issue for a
security-relevant report.

## Scope

- In scope: `scripts/`, `.github/workflows/`, CI configuration.
- Out of scope: the correctness of individual solution snippets (those are a
  historical record, including deliberately-kept failed attempts).
