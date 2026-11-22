# Source and attribution notes

- Based on two documents supplied by the project author: `readme(22001797).pdf` and `Report_22001797.pdf` for COMP2006 — Operating Systems.
- Both describe the **Simple Sorting Simulation (SSS)** assignment; the report's signed submission record is dated **5 May 2025** (the cover of the shorter README appears to contain an inconsistent year).
- The PDFs reproduce source listings for `thread.h`, `thread.c`, `main.c` and a `Makefile`. Original standalone C source files were not supplied.
- The source files under `code/` are a **portfolio reconstruction** from those listings. Formatting/comments were standardised; a `thread.o` target in `Makefile` was corrected from the original PDF's inconsistent `sorter.o` dependency heading to allow explicit build dependencies.
- In the reconstructed `thread.c`, casting the thread ID to `long` for printing makes the `%ld` format explicit on the tested Linux platform.
- `ToSort` contains the 8-number example from the original report.
- Testing notes were prepared against the reconstructed source, not against the author's original executable.

## Improvement opportunities

The educational code does not thoroughly check all allocation/thread API return values, the dynamically allocated thread argument objects are not freed, and it is limited to the fixed input array. The algorithm alternates access through a single mutex (there is no claimed sorting speedup). More thorough concurrency stress testing would be appropriate before describing the implementation as production-ready.

## Publication

Treat this as coursework-derived material. Keep the repository private until institutional academic-integrity and source-sharing rules have been checked.
