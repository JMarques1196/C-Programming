# Task:
* Identify reusable components in following code snippet, and create the appropriate .h and .c files.
* Use "static" to hide internal details

```
/* monolitico.c */
#include <stdio.h>

int counter = 0;
float sum = 0;

void add_value(float v) {
    counter++;
    sum += v;
}

float calc_average() {
    return sum / counter;
}

int main() {
    add_value(10.5);
    add_value(20.0);
    printf("Average: %.2f\n", calc_average());
    return 0;
}

```