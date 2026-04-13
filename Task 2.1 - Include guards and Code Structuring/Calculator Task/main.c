#include <stdio.h>
#include "calculator.h"

int main(void){
    
    int operation;
    int result = 0;
    int a=0;
    int b=0;

    printf("Select the operation: \n");
    printf("1: Multiplication \n");
    printf("2: Subtraction \n");
    scanf("%d", & operation);

    switch (operation)
    {
    case 1:
        printf("Enter value 1. \n");
        scanf("%d", &a);
        printf("Enter value 2. \n");
        scanf("%d", &b);
        result = multiply(a, b);
        break;

    case 2:
        printf("Enter value 1. \n");
        scanf("%d", &a);
        printf("Enter value 2. \n");
        scanf("%d", &b);
        result = subtract(a,b);
        break;
    default:
        break;
    }

    printf("Result: %d", result);
    return 0;
}