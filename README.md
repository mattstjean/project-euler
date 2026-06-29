# Project Euler Solutions in C++

Welcome! This repository is my dedicated playground for solving math and logic puzzles from [Project Euler](https://projecteuler.net) while simultaneously mastering **C++**.

## Learning Objectives

* **C++ Proficiency:** Transitioning core programming concepts into efficient, modern C++ (memory management, standard library tools).
* **Algorithm Optimization:** Moving beyond brute-force solutions to find mathematically optimal, high-performance algorithms.
* **Git Best Practices:** Utilizing a disciplined branch-per-problem Git workflow.

---

## Development Environment & Tooling

* **OS:** macOS
* **Editor:** Visual Studio Code (VS Code)
* **Compiler:** Clang (`clang++` via Apple Command Line Tools)
* **Build System:** Manual compilation for single files, migrating to CMake as structural complexity grows.

---

## Commit Standards (Conventional Commits)

To keep the project history highly readable and structured, this repository follows the **Conventional Commits** specification. Every commit message must use a structural type prefix:

* `feat(scope):` Use when adding a new solution or structural feature [1] (e.g., `feat(001): add optimal mathematical solution` [1]).
* `docs:` Use for editing documentation, tracking metrics, or updating the dashboard [1] (e.g., `docs: update progress dashboard for problem 1` [1]).
* `refactor:` Use for code changes that neither fix a bug nor add a feature, such as optimizing an algorithm's time complexity.
* `chore:` Use for updating build tasks, project configurations, or `.gitignore` entries.

---

## Branching & Contribution Workflow

To maintain a pristine history, I follow a strict feature-branch workflow for every challenge:

1. **Isolate:** Create a dedicated branch from `main`:  
   `git checkout -b problem-xyz`
2. **Solve:** Build out the localized solution directory:  
   `src/problem_xyz/solution.cpp`
3. **Verify:** Test and validate the numeric output directly on Project Euler.
4. **Merge:** Submit a local merge or Pull Request back to `main`, then update the Progress Dashboard below.

---

## Progress Dashboard

### Total Problems Solved: 0

### Archives (001 - 050)

* [ ] [Problem 1: Multiples of 3 and 5](./src/problem_001/)
* [ ] [Problem 2: Even Fibonacci Numbers](./src/problem_002/)
* [ ] [Problem 3: Largest Prime Factor](./src/problem_003/)
* [ ] [Problem 4: Largest Palindrome Product](./src/problem_004/)
* [ ] [Problem 5: Smallest Multiple](./src/problem_005/)
* [ ] [Problem 6: Sum Square Difference](./src/problem_006/)
* [ ] [Problem 7: 10001st Prime](./src/problem_007/)
* [ ] [Problem 8: Largest Product in a Series](./src/problem_008/)
* [ ] [Problem 9: Special Pythagorean Triplet](./src/problem_009/)
* [ ] [Problem 10: Summation of Primes](./src/problem_010/)

---

> *"Computers are useless. They can only give you answers." — Pablo Picasso* (But they do make checking massive prime numbers a lot faster.)
