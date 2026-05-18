# AF 3.3 | Formative Activity 3.3  
## Modular Contact Management System

### Schedule
Takes place during the **5th week of April** and **1st week of May 2026**.

---

## Theme
Modular project with separation of responsibilities, integrating the principles of **RF 3.1**, **RF 3.2**, and **RF 3.3**.

---

## Skills Developed
- Structure a system into multiple modules with clear separation of responsibilities  
- Ensure low coupling between modules, communicating only through public interfaces  
- Apply encapsulation using `static` variables and functions  
- Produce readable, well-documented code with consistent naming  
- Identify appropriate boundaries between modules based on system requirements  

---

## Activity Description
In this activity, you must develop a contact management system organized into **four independent modules**.

Each module has a single responsibility and communicates with others only through its public interface (`.h` files).

The `main.c` file should only orchestrate user interaction and **must not contain business logic**.

### Modules to Implement
- **validation** – email and phone validation (reusable helper functions)  
- **contact** – `Contact` structure and operations on a single contact (create, validate, display)  
- **list** – management of the contact collection (add, list, search)  
- **io** – reading and writing contacts to a text file  

---

## Reflection Question
*(Answer in a short report of 5–10 lines)*

The `validation` module could have been integrated into the `contact` module.

- Justify the decision to keep them separate (or argue for integration, if that is your choice)  
- How did you ensure that modules communicate only through public interfaces and do not directly access each other’s internal state?  

---

## Starter Code
No starter code is provided for this activity.

You must build the system **from scratch**, following the specified requirements.

---

## Tasks
- Design the system architecture:
  - list the modules  
  - define responsibilities  
  - identify public functions (table or structured list)  

- Implement each module with its corresponding pair of files (`.h` and `.c`)  
- Apply proper encapsulation  
- Ensure modules communicate exclusively through public interfaces  
- Document all public functions in the `.h` files:
  - purpose  
  - parameters  
  - return value  
  - preconditions (when relevant)  

- Create a `main.c` demonstrating the system’s main features  
- Produce a report justifying design decisions, including the reflection question  

---

## Expected File Structure

```bash
project/
├── include/
│   ├── validation.h
│   ├── contact.h
│   ├── list.h
│   └── io.h
├── src/
│   ├── validation.c
│   ├── contact.c
│   ├── list.c
│   ├── io.c
│   └── main.c
└── Makefile (optional)