# Verification record

The C files in this portfolio were reconstructed from supplied PDFs, compiled with `make` (GCC with `-Wall -pthread`), and executed locally.

| Input scenario | Number of integers | Result |
| --- | ---: | --- |
| Report example: `5 9 1 4 8 0 12 7` | 8 | Passed: ascending order |
| Report example with duplicates | 10 | Passed: ascending order |
| Already sorted | 6 | Passed |
| Reverse sorted | 7 | Passed |
| Negative integers and duplicates | 6 | Passed |
| Single element | 1 | Passed |
| Empty input | 0 | Passed (empty sorted output) |
| Maximum-sized reversed input | 200 | Passed |

**Scope:** These are additional checks of the reconstructed program, not independent proof that the original university submission passed an automated test suite. No concurrency stress testing, sanitizer analysis or formal race-freedom proof was performed.
