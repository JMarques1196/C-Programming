# GreenTrack 🌱

A community garden management system developed in C, as part of the Programming Laboratory course.

## Features

- Plant registration and listing
- Watering log with history
- Pending task management
- Data persistence via CSV files

## Project Structure

```
GreenTrack/
├── src/
│   ├── main.c          # Entry point and main menu
│   ├── plants.c        # Plant management
│   ├── watering.c      # Watering records
│   ├── tasks.c         # Task management
│   └── data.c          # Aggregated persistence
├── include/
│   ├── types.h         # Data structures and constants
│   ├── plants.h
│   ├── watering.h
│   ├── tasks.h
│   └── data.h
├── tests/
│   ├── test_plants.c       # Unit tests — plants module
│   ├── test_watering.c     # Unit tests — watering module
│   ├── test_tasks.c        # Unit tests — tasks module
│   └── test_integration.c  # Integration tests
└── Makefile
```

## Build & Run

**Main program:**
```bash
make
./program
```

**Tests:**
```bash
make test
```

**Clean:**
```bash
make clean
```

## Requirements

- GCC
- Make
- Linux or Windows

## Notes

Data is persisted in CSV files (`plants.csv`, `watering.csv`, `tasks.csv`) created automatically in the execution directory.