# AF 4.2 | Unit and Integration Testing in C

## Overview

This activity provides a two-module project for managing game scores. The individual functions are correct, but there is a bug in the way they are combined. The goal is to write unit tests and integration tests, and observe that **only the integration test catches the bug** — illustrating why both types of testing are necessary.

---

## Provided Code

### `pontuacao.h`

```c
#ifndef PONTUACAO_H
#define PONTUACAO_H

/* Applies a percentage bonus: returns points + (points * bonus / 100) */
int aplicar_bonus(int pontos, int bonus);

/* Applies a penalty: subtracts penalizacao; never goes below zero */
int aplicar_penalizacao(int pontos, int penalizacao);

#endif
```

### `pontuacao.c`

```c
#include "pontuacao.h"

int aplicar_bonus(int pontos, int bonus) {
    return pontos + (pontos * bonus / 100);
}

int aplicar_penalizacao(int pontos, int penalizacao) {
    if (penalizacao > pontos)
        return 0;
    return pontos - penalizacao;
}
```

### `nivel.c`

```c
#include "pontuacao.h"

/*
 * Calculates the final score for a level:
 * applies the bonus first, then the penalty to the result.
 * Expected: aplicar_penalizacao( aplicar_bonus(points, bonus), penalty )
 */
int calcular_pontuacao_nivel(int pontos, int bonus, int penalizacao) {
    int com_bonus = aplicar_bonus(pontos, bonus);
    return aplicar_penalizacao(pontos, penalizacao); /* BUG: should use 'com_bonus', not 'pontos' */
}
```

---

## Base Level

### Learning Objectives

- Distinguish unit tests from integration tests in practice
- Implement unit tests for individual functions
- Implement an integration test and recognise that it can fail even when unit tests pass

### Tasks

1. **Create unit tests** in `test_pontuacao.c` with one test function per module function (`testar_aplicar_bonus()` and `testar_aplicar_penalizacao()`), covering:
   - Normal case
   - 0% bonus (boundary)
   - Penalty exactly equal to the available points (boundary)
   - Penalty greater than the available points

2. **Compile and confirm** all unit tests pass:

   ```bash
   gcc pontuacao.c test_pontuacao.c -o test_pontuacao
   ./test_pontuacao
   ```

3. **Create an integration test** in `test_integracao.c` with a `testar_calcular_nivel()` function that validates:
   - Score with 50% bonus and no penalty (e.g. 100 points → expected 150)
   - Score with bonus and penalty: verify the penalty is applied **after** the bonus (e.g. 100 points, 50% bonus, penalty 20 → expected 130, not 80)

4. **Compile and observe** that the integration test fails. Record the actual and expected values:

   ```bash
   gcc pontuacao.c nivel.c test_integracao.c -o test_integracao
   ./test_integracao
   ```

5. **Fix the bug** in `nivel.c` and re-run both test suites to confirm all tests pass.

6. **Write a short report (8–12 lines)** that:
   - Describes the bug and explains why unit tests did not catch it
   - Answers the reflection question below

### Reflection Question (Base Level)

> The functions `aplicar_bonus()` and `aplicar_penalizacao()` were correct and their tests passed. The bug was in how they were combined. **What does an integration test verify that a unit test cannot?**

### Self-Assessment Criteria (Base Level)

| Criterion                                                                 | Weight |
| ------------------------------------------------------------------------- | ------ |
| Quality and coverage of unit tests (normal, boundary, error cases)        | 30%    |
| Correct integration test that catches the bug before the fix              | 30%    |
| Effective bug fix with confirmation that all tests pass                   | 20%    |
| Report explaining the complementarity of tests and answering the question | 20%    |

---

## Advanced Level

Includes all Base Level tasks, plus the following additions.

### Additional Learning Objectives

- Analyse functions before testing them: identify valid inputs, invalid inputs, boundary cases, and potential failure modes
- Organise production code and test code in separate directories
- Compile multi-file projects with `-Iinclude`

### Additional Tasks

1. **Organise the project** using the recommended structure before writing tests:

   ```
   project/
   ├── include/
   │   └── pontuacao.h
   ├── src/
   │   ├── pontuacao.c
   │   └── nivel.c
   └── tests/
       ├── test_pontuacao.c
       └── test_integracao.c
   ```

2. **Adapt the compilation commands** to use `-Iinclude` and the correct paths.

3. **Record a function analysis** as comments at the top of each test file, answering:
   - What are the valid inputs and boundary cases?
   - Can the function produce unexpected results for any input?
   - Does the function modify any external data?

4. **Extend the report** (total 12–18 lines) with an answer to the advanced reflection question below.

### Reflection Question (Advanced Level)

> If each developer on a team only tests their own functions individually, what types of bugs go undetected? What would need to be added to the testing process to cover them? Give a concrete example based on this activity.

### Self-Assessment Criteria (Advanced Level)

| Criterion                                                                | Weight |
| ------------------------------------------------------------------------ | ------ |
| Prior function analysis recorded as comments                             | 15%    |
| Correct directory structure and compilation with `-Iinclude`             | 10%    |
| Quality and coverage of unit tests                                       | 25%    |
| Correct integration test that catches the bug before the fix             | 25%    |
| Effective bug fix                                                        | 10%    |
| Report with complementarity analysis and reasoned answer to the question | 15%    |

---

## Timeline

Weeks 2 and 3 of May 2026.

---

> **Note:** Publishing your solution to the course forum is not required.
