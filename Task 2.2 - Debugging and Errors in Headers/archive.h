/* 

int calc(int x);

#endif
The error is that the header guard is missing. 
To fix this, you should add a header guard to prevent multiple 
inclusions of the same header file. 

The pre-processor reads archive.h

    finds int calc(int x); - OK, it is a function declaration
    finds #endif - No #if or #ifndef, so it will throw an error because 
    it expects a matching #if or #ifndef before #endif.
    generates an error about unmatched #endif.
    fails to compile.


Here is the corrected code:
*/

#ifndef ARCHIVE_H
#define ARCHIVE_H

int calc(int x);

#endif // ARCHIVE_H
