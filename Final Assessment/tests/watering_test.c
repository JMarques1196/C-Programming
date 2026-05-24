#include "../include/plants.h"
#include "../include/watering.h"
#include "../include/types.h"
#include <stdio.h>
#include <assert.h>

/* 4 - Test Suite for register_watering() */
void test_register_watering_normal(void)
{
    /* Arrange */
    reset_plants();
    reset_waterings();
    add_plant("name", "species", "01/01/2026", 10);

    /* Act */
    int result = register_watering(1, 10, 500);

    /* Assert */
    if (!result)
    {
        printf("FAILURE: test_register_watering_normal - expected 1, got %d\n", result);
    }
    assert(result);

    printf("OK: test_register_watering_normal\n");
}

void test_register_watering_limit(void)
{
    /* Arrange */
    reset_plants();
    reset_waterings();
    add_plant("name", "species", "01/01/2026", 10);

    for (int i = 0; i < MAX_WATERINGS; i++)
    {
        register_watering(1, 10, 500);
    }

    /* Act */
    int result = register_watering(1, 10, 500);

    /* Assert */
    if (result)
    {
        printf("FAILURE: test_register_watering_limit - expected 0, got %d\n", result);
    }
    assert(!result);

    printf("OK: test_register_watering_limit\n");
}

void test_register_watering_error(void)
{
    /* Arrange */
    reset_plants();
    reset_waterings();

    /* Act */
    int result = register_watering(-1, 10, 500);

    /* Assert */
    if (result)
    {
        printf("FAILURE: test_register_watering_error - expected 0, got %d\n", result);
    }
    assert(!result);

    printf("OK: test_register_watering_error\n");
}

int main(void)
{
    printf("\n=== RUNNING TESTS: WATERING MODULE ===\n");
    test_register_watering_normal();
    test_register_watering_limit();
    test_register_watering_error();
    printf("=========================================\n");
    return 0;
}