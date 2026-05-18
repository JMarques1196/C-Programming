## AF 3.2 | Formative Activity 3.2 — Creating a Module in C

**Topic:** Modularity in C (header + source, encapsulation) based on RF 3.2.

### Competencies

- Structure a C module with separation between interface (`.h`) and implementation (`.c`);
- Apply encapsulation using `static` variables/functions;
- Define a clear and cohesive public interface.

### Activity Description

In this activity you must create a `gerador` (*generator*) module that provides functionality to generate and manage random numbers, with seed control and statistics querying (how many numbers were generated, the last value, etc.). The module must hide its internal implementation and expose only well-defined functions. The `main.c` file must demonstrate the use of the module without directly accessing its internal state.

The activity consists of:

1. Creating the interface file `gerador.h` with the public function prototypes and their documentation;
2. Creating the implementation file `gerador.c` with `static` variables to store state, `static` auxiliary functions if needed, and the implementation of the public functions;
3. Creating a `main.c` that uses exclusively the module's public functions to demonstrate its behaviour;
4. Documenting each public function in the `.h` file with its purpose, parameters, and return value.

### Reflection Question *(to be answered in a short report of 5–10 lines)*

It is suggested that you develop a `gerador_inicializar` function that sets the seed and resets the internal state. Would this violate the Single Responsibility Principle? Present and justify your decision. Additionally, what is your reasoning for what belongs in the public interface (`.h`) versus what should remain hidden in the `.c`?

### Original Code

No code is provided for this activity — the module must be created from scratch, respecting the requirements described above.

### Tasks

1. Create `gerador.h` with the prototypes and documentation of the public functions;
2. Create `gerador.c` with `static` state variables, private `static` auxiliary functions if needed, and the implementation of the public functions;
3. Create `main.c` that uses only the module's public interface, without direct access to internal variables;
4. Apply clear and consistent names, using the `gerador_` prefix on all public functions;
5. Insert comments that explain implementation *decisions*, not just what the code does;
6. Produce the code and a report justifying the design decisions, including the answer to the reflection question.