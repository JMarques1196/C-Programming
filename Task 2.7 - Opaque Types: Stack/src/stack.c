/* Implement the stack functions */

#include <stdio.h>
#include <stdlib.h>
#include "../include/stack.h"

/********** Definition of the Stack structure **********/
struct Stack {
    int *data;      // Array for storing stack elements
    int top;        // Index of the top of the stack
    int capacity;   // Maximum capacity of the stack
};

/* Notes:
A pointer is used for int data to allow dynamic allocation of the stack's storage. It allows us to create a stack of any size at runtime,
 as the size can be determined when the stack is created. It will allocate memory to store indivual elements of the stack, and we can easily resize it if needed.
The top variable keeps track of the current position of the top element, 
and capacity defines the maximum number of elements the stack can hold.
The Top and Capacity don't need to be a pointer because they are just integers 
that can be stored directly in the structure.
*/

/********** Stack function implementations **********/

// Creates an empty stack with capacity N
// StackPtr is a pointer to the Stack structure, which is an opaque type defined in the header file.
StackPtr stack_criar(int size) {
    if(size <=0) {
        printf("Error: Stack size must be greater than 0.\n");
        return NULL;
    }
    StackPtr new_stack = (StackPtr)malloc(sizeof(struct Stack));
    if(new_stack == NULL) {
        printf("Error: Failed to allocate memory for stack.\n");
        return NULL;
    }
    new_stack->data = (int*)malloc(size * sizeof(int)); // new_stack->data points and accesses the data array within the Stack structure.
    if(new_stack->data == NULL) {
        free(new_stack);
        printf("Error: Failed to allocate memory for stack data.\n");
        return NULL;
    }
    new_stack->top = -1;
    new_stack->capacity = size;
    return new_stack;
}