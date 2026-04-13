#include "stats.h"

static int counter = 0;
static float sum = 0;

void add_value(float v) {
    counter++;
    sum += v;
}

float calc_average() {
    return sum / counter;
}
