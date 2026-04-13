#include <stdio.h>
#include "course.h"
#include "student.h"
/*

Without course.h and student.h guards, this will throw erros when compiling
When compiling this code, student.h contents will be used in course.h and again
when importing student.h into main, resulting in multiple instances of the Student object.

Include guards make sure that a header file is only included once
*/



int main(void){
    return 0;
}