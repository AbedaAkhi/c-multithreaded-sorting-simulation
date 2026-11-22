# Simple Sorting Simulation (SSS) — Multithreaded C

**Curtin University | COMP2006 — Operating Systems | Semester 1, 2025**  
**Project type:** Individual academic assignment  
**Focus:** POSIX threads, thread coordination, mutexes, condition variables, file I/O and C programming

## Overview

This project is a two-thread integer sorting simulation written in C. Two worker threads take turns comparing and swapping adjacent integer pairs. Thread 1 processes even-indexed pairs (`A[0]`–`A[1]`, `A[2]`–`A[3]`, etc.); Thread 2 processes odd-indexed pairs (`A[1]`–`A[2]`, `A[3]`–`A[4]`, etc.). The threads coordinate through shared state protected by a POSIX mutex and a condition variable. The program reads integers from a `ToSort` file and displays the sorted array and swap counts.

This is an operating-systems and concurrency programming exercise—not a security tool or a performance claim about parallel sorting.

## My work

- Implemented a C sorting simulation using two POSIX threads and alternating even/odd comparison passes.
- Shared an array and coordination flags across worker threads.
- Used `pthread_mutex_t` and `pthread_cond_t` to coordinate access to shared state.
- Used file input for test integers and generated a sorted result and swap counts.
- Compiled the program with GCC and a Makefile, and documented test runs.

## Repository structure

```text
.
├── README.md
├── .gitignore
├── code/
│   ├── Makefile
│   ├── ToSort
│   ├── main.c
│   ├── thread.c
│   └── thread.h
└── docs/
    ├── case-study.md
    ├── verification.md
    └── source-notes.md
```

## Build and run

Use a Linux environment with `gcc`, `make` and POSIX threads support:

```bash
cd code
make
./sss
make clean
```

The executable reads numbers from `code/ToSort`. Change that file to try another input (up to 200 integers in this coursework implementation).

Sample input:

```text
5 9 1 4 8 0 12 7
```

Expected sorted array:

```text
0 1 4 5 7 8 9 12
```

The order of the thread-ID output lines may differ by run.

## Verification

This portfolio reconstruction compiled with GCC and was checked with eight illustrative input sets, including the two cases documented in the assignment report, duplicates, sorted/reverse arrays, negative values, a single value, an empty file and 200 integers. See [`docs/verification.md`](docs/verification.md).

## Limitations and provenance

**Important:** The user-provided source was an assignment report and README in PDF, **not the original submitted `.c` files**. The files under `code/` were reconstructed from source listings in those PDFs for this portfolio. Formatting and comments have been normalised and a Makefile dependency-target typo corrected. The resulting build has been re-tested, but this repository should not be treated as a byte-for-byte archive of the original submission.

The coursework implementation intentionally uses alternating thread turns, so there is no claim of parallel speedup. Input handling, resource cleanup and error checks would need hardening for production use. See [`docs/source-notes.md`](docs/source-notes.md).

The assignment reports and course handouts are not included. Confirm university rules before publishing assessed source material publicly.
