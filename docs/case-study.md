# Case Study — Simple Sorting Simulation

## Objective
Implement a two-thread integer sorting simulation in C while coordinating shared-memory access safely.

## Implementation
- `thread.h` defines the array (maximum size 200), shared mutex and condition variable, turn/completion flags and per-thread arguments.
- `thread.c` contains an alternating even-index/odd-index adjacent-pair comparison routine. Each thread locks the shared state before performing its turn, uses a condition variable to wait for its turn, records swaps and signals the other thread.
- `main.c` reads values from `ToSort`, initialises synchronization objects, starts and joins two worker threads, and reports the sorted result and total swaps.
- `Makefile` builds the `sss` executable using GCC and the pthread flag.

## Original report evidence
The submission report documents example runs with eight integers and with repeated values. It also describes the use of `pthread_mutex_t`, `pthread_cond_t`, `pthread_create`, `pthread_join` and the Makefile.

## Skills demonstrated
C programming · POSIX Threads · Thread Synchronization · Mutexes · Condition Variables · Shared State · Linux/GCC · File I/O · Debugging

## Relevance
An operating-systems programming project demonstrating foundational concurrency and low-level programming concepts. These are useful for understanding software behaviour and system-level bugs, though this is not itself a cybersecurity investigation or exploit.

## Caveats
This code was reconstructed from the assignment PDFs as a reproducible demonstration. It is not the original repository or a claim of production readiness. Review `source-notes.md` before republishing.
