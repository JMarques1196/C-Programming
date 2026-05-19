# AF 4.1 — Password Validation with Unit Tests

## Overview

A authentication system requires a function that classifies the strength of a password based on its length, according to the following table:

| Password Length       | Classification              |
| --------------------- | --------------------------- |
| 0 to 3 characters     | "Fraca" (Weak)              |
| 4 to 7 characters     | "Media" (Medium)            |
| 8 to 15 characters    | "Forte" (Strong)            |
| 16 or more characters | "Muito Forte" (Very Strong) |

A first programmer wrote the function below, but it contains **2 bugs**. The function receives the password length (a non-negative integer) and a pointer to a destination string where the classification will be copied. It returns `1` if the length is valid and the classification was assigned, or `0` on error.

---

## Original Code (with bugs)

```c
/* senha.c */
#include <string.h>

int classificar_senha(int comprimento, char *classe) {
    if (comprimento < 0 || classe == NULL)
        return 0;
    if (comprimento <= 3)
        strcpy(classe, "Fraca");
    else if (comprimento <= 7)
        strcpy(classe, "Media");
    else if (comprimento <= 15)
        strcpy(classe, "Forte");
    else if (comprimento >= 16 && comprimento <= 30) /* BUG 1: lengths > 30 are not captured */
        strcpy(classe, "Muito Forte");
    return 1; /* BUG 2: returns 1 even when comprimento < 0 */
}
```

---

## Project Structure

```
.
├── senha.c       # The function under test (original with bugs → then corrected)
├── senha.h       # Function declaration
├── testes.c      # Test suite + main()
└── README.md
```

### Build & Run

```bash
gcc senha.c testes.c -o prog
./prog
```

---

## Tasks

### Base Level

- Analyse the function's contract: what it receives, what it guarantees, and what it returns on error
- Write a test suite using `printf` inside `testar_senha()` that validates:
  - Valid lengths in each interval, including all boundary values: `0, 3, 4, 7, 8, 15, 16, 31`
  - Invalid length (`-1`) — must return `0` and not modify the destination string
  - `NULL` pointer — must return `0` without causing a segmentation fault
- Run the tests against the buggy code and record all detected errors
- Fix the function so it fully meets the specification
- Re-run the tests and confirm all pass after the fix
- Write a short report (6–10 lines) identifying the 2 bugs and answering the reflection question

**Reflection question (Base):** In this activity you used `printf` to test the function. What would happen if you used `assert()` instead — would you still see all errors at once? What is the practical difference between the two approaches?

---

### Advanced Level

Includes all Base Level tasks, plus:

- Write a second test suite `testar_senha_assert()` using the `assert()` macro with the same tests. Run it against the buggy code and observe: how many errors are visible at once? Compare with the `printf` approach.
- Explore `NDEBUG` — compile twice (with the bug still present):
  ```bash
  gcc senha.c testes.c -o prog_debug
  gcc -DNDEBUG senha.c testes.c -o prog_release
  ```
  Observe and describe the different behaviour between the two versions.
- Extend the report to 10–15 lines total, adding:
  - A practical comparison between `printf` and `assert()`
  - Answer to the advanced reflection question

**Reflection question (Advanced):** You experienced two distinct behaviours: with `assert()` the program terminates on the first error; with `printf` it continues and shows all of them. You also tried `-DNDEBUG`, which removes the assertions. In which phase of development do you prefer each approach: during initial testing, while debugging a specific error, or in production code? Justify your answer.

---

## Evaluation Criteria

### Base Level

| Criterion                                                               | Weight |
| ----------------------------------------------------------------------- | ------ |
| Correct identification of the function's contract                       | 15%    |
| Full test coverage (all intervals, boundaries, invalid inputs, NULL)    | 40%    |
| Effective correction of the original function                           | 25%    |
| Clear report identifying the bugs and answering the reflection question | 20%    |

### Advanced Level

| Criterion                                                                | Weight |
| ------------------------------------------------------------------------ | ------ |
| Correct identification of the function's contract                        | 10%    |
| Full test coverage in both approaches                                    | 25%    |
| Correct use of `assert()` and `printf` for verification                  | 20%    |
| Effective correction of the original function                            | 15%    |
| Correct exploration of `NDEBUG` and description of observed behaviour    | 10%    |
| Report with comparison of approaches and reasoned answer to the question | 20%    |
