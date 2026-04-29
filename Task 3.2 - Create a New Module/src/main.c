#include <stdio.h>
#include <stdlib.h> 
#include <time.h>
#include "../include/generator.h"

int main(void){
/* 
    Switch case:
    1. Generate a random number using Time
    2. Generate a random number using a seed
    3. Show statistics: Last number generated, total numbers generated, etc.
*/
    int option;

    printf("Welcome to the Random Number Generator!\n");
    printf("Please select an option:\n");
    do{
        unsigned int scale = 0;
        printf("1. Generate a random number using Time\n");
        printf("2. Generate a random number using a seed\n");
        printf("3. Show statistics\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            generator_init(time(NULL)); // Initialize the generator with the current time as seed
            printf("Enter a scale value: ");
            scanf("%u", &scale);
            printf("Generated random number: %d\n", random_generator(scale));
            break;
        case 2:
            unsigned int seed;
            printf("Enter a seed value: ");
            scanf("%u", &seed);
            generator_init(seed); // Initialize the generator with the user-provided seed
            printf("Enter a scale value: ");
            scanf("%u", &scale);
            printf("Generated random number: %d\n", random_generator(scale));
            break;
        case 3:
            printf("Last generated number: %d\n", get_last_generated_number());
            printf("Total numbers generated: %d\n", get_total_generated_numbers());
            break;
        default:
            break;
        }
    } while (option != 4);
}