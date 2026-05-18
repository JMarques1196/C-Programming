/* programa_original.c */
#include <stdio.h>


/* Issues found:
Naming: p and f are not descriptive names.
No meaningful comments explaining the purpose of the functions.
No error handling for invalid input (e.g., null pointer, negative size).
printing function is printing and counting at the same time, so the name should reflect that
lim is not explained, it is not clear what it represents
*/

/* Sum of even positive numbers */
/* int p(int *a, int n){
    int i, s = 0;
    for(i = 0; i < n; i++){
        if(a[i] > 0){
            if(a[i] % 2 == 0){
                s += a[i];
            }
        }
    }
    return s;
}

/* Print the values of the array */
/*
int f(int *a, int n, int lim){
    int i, c = 0;
    for(i = 0; i < n; i++){
        if(a[i] > 0){
            if(a[i] <= lim){
                printf("%d ", a[i]);
                c++;
            }
        }
    }
    return c;
} */

/* Refactored code with improvements:*/
/* Sum of even positive numbers */
int sumEvenPositive(int *a, int n){
    if(a == NULL || n <= 0){
        return 0; // Handle invalid input
    }
    int i, s = 0;
    for(i = 0; i < n; i++){
        if(a[i] > 0){
            if(a[i] % 2 == 0){ // Check if the number is even 
                s += a[i];
            }
        }
    }
    return s;
}

/* Print the values of the array */
int printAndCountPositiveValues(int *a, int n, int lim){
    // lim represents the upper limit for the values to be printed and counted
    if(a == NULL || n <= 0){
        return 0; // Handle invalid input
    }
    int i, c = 0;
    for(i = 0; i < n; i++){
        if(a[i] > 0){
            if(a[i] <= lim){
                printf("%d ", a[i]);
                c++;
            }
        }
    }
    return c;
}

int main(){
    int v[] = {-3, 4, 7, 8, -1, 10, 2, 15};
    int r = sumEvenPositive(v, 8);
    printf("Resultado: %d\n", r);
    int x = printAndCountPositiveValues(v, 8, 10);
    printf("Contagem: %d\n", x);
    return 0;
}