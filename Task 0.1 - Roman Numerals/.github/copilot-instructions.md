# Copilot Instructions - Roman Numerals (Lab. Programação)

## Project Overview
This is a university programming lab assignment (Task 0.1) for converting between Arabic and Roman numerals, implemented in C. Part of the Open University "Lab. Programação" course (First Year, Second Semester).

## Build & Run
- **Build command**: Use the VS Code task "Compile C with warnings" or run:
  ```bash
  clang -Wall -Wextra -Wpedantic programa.c -o programa
  ```
  Note: The task references `programa.c`, but the current source file is `main.c`. You may need to update the task or rename the file.
  
- **Compiler**: Clang with strict warnings enabled (`-Wall -Wextra -Wpedantic`)
- **Run**: `./programa` after compilation

## Code Conventions
- **Language**: Standard C (no C++ features)
- **Warning-free code**: All code must compile without warnings under strict flags
- **Educational context**: Code should be clear and well-documented for learning purposes
- **Portuguese context**: Project paths and documentation may use Portuguese (e.g., "Primeiro Ano", "Lab. Programação")

## Expected Functionality
Based on the project name "Roman Numerals", implementations should handle:
- Conversion from Arabic numbers (1, 2, 3...) to Roman numerals (I, II, III...)
- Potentially bidirectional conversion (Roman to Arabic)
- Input validation for valid ranges and formats
- Standard Roman numeral rules (I=1, V=5, X=10, L=50, C=100, D=500, M=1000)

## Development Notes
- Main source file: [main.c](main.c) (currently empty - awaiting implementation)
- Build configuration references `programa.c` - verify correct source filename
- This is an academic assignment - prioritize code clarity and educational value over optimization
