/* projeto.h - With Bad Practices */

#ifndef PROJETO_H
#define PROJETO_H

int funcao1(int a, int b) {
    // 50 lines of code...
    return a + b;
}

int funcao2(int x) {
    // 50 lines of code...
    return x * 2;
}

// ... 18 similar functions ...

#endif

/* Issues with this code: */
/* Compile Time: By declaring all the functions in the header file,
the code is compiled everytime the header is included, leading to longer build times.
20 functions with 50 lines each means 1000 lines of code being compiled every time, which is inefficient. 

Multiple Definitions: If this header is included in multiple source files, 
it will lead to multiple definitions of the same functions, causing linker errors. 
Each source file that includes this header will have its own copy of the functions, 
which is not intended. Static should be used to limit the scope of the functions to the file they are defined in, 
or the functions should be declared in a source file and only their prototypes should be in the header.

Maintainability: Having all the code in the header file makes it harder to maintain and read.
It mixes interface (function declarations) with implementation (function definitions), which can lead to confusion and makes it difficult to navigate the codebase. 


Exposes Internal Details: By defining the functions in the header, you expose the internal implementation details to any file that includes it.
This can lead to tight coupling between modules and makes it harder to change the implementation without affecting other parts of the code.
*/