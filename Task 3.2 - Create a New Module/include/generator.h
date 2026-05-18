#ifndef GENERATOR_H
#define GENERATOR_H

void generator_init(unsigned int seed);
int random_generator(unsigned int scale);
int get_last_generated_number(void);
int get_total_generated_numbers(void);


#endif /* GENERATOR_H */