#include "student.h"
/* 
Instead of the include guards bellow, a widely used solution is #pragma once, 
which is a non standard but widely supported preprocessor directive that serves the same 
purpose as include guards, it tells the compiler to include the header file only once, 
regardless of how many times it is included in the code.
*/
#ifndef COURSE_H // This is a pre proecessor macro, it checks if COURSE_H is not defined 
// The marcro name is usually the same as the header file name, but in uppercase and with _ instead of .
#define COURSE_H // If it is not defined, it defines it, this way if the header is included again, the content will be ignored   

typedef struct{
    Student students[100];
    char name[100];
}   Course;

#endif