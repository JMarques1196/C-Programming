/* Generator functions
    Generate Random numbers.
    Seed control
    Statistics: Numbers generated, last number generated, etc.
*/

#include <stdio.h>
#include <stdlib.h>
#include "../include/generator.h"

static int last_generated_number = 0; // Variable to store the last generated number
static int total_generated_numbers = 0; // Variable to count the total number of generated numbers

// Generator initialization function does not violate SRP
// The responsibility of gerador_inicializar is to prepare the generator for use. 
// This includes both setting the seed and resetting internal state. 
// These actions are conceptually part of the same responsibility (initialization), so this does not violate SRP.

void generator_init(unsigned int seed) {
    srand(seed); // Initialize the random number generator with the provided seed
}

int random_generator(unsigned int scale) {
    int random_number = rand() % scale; // Generate a random number between 0 and scale-1
    last_generated_number = random_number;
    total_generated_numbers++;
    return random_number;
}

int get_last_generated_number(void) {
    return last_generated_number; // Return the last generated number
}   

int get_total_generated_numbers(void) {
    return total_generated_numbers; // Return the total count of generated numbers
}