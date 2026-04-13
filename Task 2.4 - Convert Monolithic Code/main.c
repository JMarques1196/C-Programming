# include "stats.h"
# include <stdio.h>

int main() {
    add_value(10.5);
    add_value(20.0);
    printf("Average: %.2f\n", calc_average());
    return 0;
}