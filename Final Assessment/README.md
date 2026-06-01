# GreenTrack — Community Garden Management System

A community garden management system written in C, developed as part of my 
Computer Science degree at Universidade Aberta.

## What it does
Manages plants, watering schedules, and maintenance tasks, persisting all 
data to CSV files across sessions.

## What this project covers
This project was completed in two stages:

**Stage 1 — Bug fixing and modular architecture**
- Identified and documented 16 bugs in a monolithic codebase (logic errors, 
buffer overflows, file handling issues, off-by-one errors)
- Redesigned the codebase into a modular architecture with full encapsulation 
— No module accesses another's internal state directly

**Stage 2 — Code quality and testing**
- Applied readability practices: guard clauses, single-responsibility functions, 
expressive naming, Doxygen-style interface documentation
- Implemented unit tests covering normal, boundary, and error cases across all modules
- Implemented integration tests validating data persistence and inter-module communication
- Automated the full test suite via Makefile (`make test`)
- Tests uncovered real NULL dereference bugs that were fixed and documented

## How to run
```bash
make        # builds the main program
make test   # runs the full test suite
```

## Stack
C99 · POSIX · Makefile
