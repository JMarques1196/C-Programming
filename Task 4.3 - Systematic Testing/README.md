# AF 4.3 | Formative Activity 4.3 - Systematic Testing and Automation

## Schedule

Takes place during the 3rd week of May 2026.

## Topic

Systematic testing: contracts, coverage, and automation (RF 4.3).

## Activity Description

You are provided with two functions containing documented contracts to manage a list of temperatures. One function is correct and serves as a model. The other contains an error that can only be detected if the tests are derived from the contract, rather than just the code's logical branches. This activity consists of writing systematic tests and automating their execution.

---

## Provided Code

### File: `include/temperaturas.h`

```c
#ifndef TEMPERATURAS_H
#define TEMPERATURAS_H

/*
 * Contract for registar_temperatura:
 * - Pre-condition  : lista != NULL; capacidade > 0; 0 <= indice < capacidade
 * - Post-condition : lista[indice] == valor; remaining elements remain unchanged
 * - Return         : 1 on success, 0 on error
 */
int registar_temperatura(float *lista, int capacidade, int indice, float valor);

/*
 * Contract for media_temperaturas:
 * - Pre-condition  : lista != NULL; n > 0; resultado != NULL
 * - Post-condition : *resultado == arithmetic mean of the first n elements
 * - Return         : 1 on success, 0 on error
 */
int media_temperaturas(float *lista, int n, float *resultado);

#endif
```
