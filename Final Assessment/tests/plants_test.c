#include "../include/plants.h"
#include "../include/watering.h"
#include "../include/types.h"
#include <stdio.h>
#include <assert.h>

/* 1 - Test Suite for add_plant() */
void test_add_plant_normal(void)
{
    // Arrange
    reset_plants(); // Ensures the test starts from scratch, overwriting old data
    // Act
    int result = add_plant("name", "species", "01/01/2026", 10);
    int total = current_total_plants();
    // Assert
    if (!result)
    {
        printf("FAILURE: failed to add plant\n");
    }
    assert(result);
    printf("OK: Plant successfully added\n");

    if (total != 1)
    {
        printf("FAILURE: failed to increment plant counter\n");
    }
    assert(total == 1);
    printf("OK: Counter successfully incremented.\n");

    printf("OK: test_add_plant_normal\n");
}

void test_add_plant_limit(void)
{
    // Arrange
    reset_plants();

    // Act
    for (int i = 0; i < MAX_PLANTS; i++)
    {
        add_plant("name", "species", "01/01/2026", 10); // Fill up the plant capacity completely
    }

    int result = add_plant("name", "species", "01/01/2026", 10); // Attempt to add one more plant beyond the limit
    // Assert
    if (result)
        printf("FAILURE: Plant added without respecting limits\n");
    assert(!result);

    int total = current_total_plants();
    if (total != MAX_PLANTS)
    {
        printf("FAILURE: failed to respect the plant limit\n");
    }
    assert(total == MAX_PLANTS);
    printf("OK: test_add_plant_limit\n");
}

void test_add_plant_error(void)
{
    // Arrange
    reset_plants();

    /* Act + Assert - NULL parameter */
    int result = add_plant(NULL, "species", "01/01/2026", 10);
    if (result)
    {
        printf("FAILURE: Function added NULL parameters\n");
    }
    assert(!result);

    /* Act + Assert - invalid interval */
    result = add_plant("name", "species", "01/01/2026", 0);
    if (result)
        printf("FAILURE: test_add_plant_error - expected 0, got %d\n", result);
    assert(!result);

    printf("OK: test_add_plant_error\n");
}

/* 2 - Test Suite for plant_exists() */
void test_plant_exists_normal(void)
{
    /* Arrange */
    reset_plants();
    add_plant("name", "species", "01/01/2026", 10);

    /* Act */
    int result = plant_exists(1); // The ID of the first plant is always 1

    /* Assert */
    if (!result)
        printf("FAILURE: test_plant_exists_normal - expected 1, got %d\n", result);
    assert(result);

    printf("OK: test_plant_exists_normal\n");
}

void test_plant_exists_limit(void)
{
    /* Arrange */
    reset_plants();
    for (int i = 0; i < MAX_PLANTS; i++)
    {
        add_plant("name", "species", "01/01/2026", 10);
    }

    /* Act */
    int result = plant_exists(MAX_PLANTS);

    /* Assert */
    if (!result)
        printf("FAILURE: test_plant_exists_limit - last plant not found\n");
    assert(result);

    printf("OK: test_plant_exists_limit\n");
}

void test_plant_exists_error(void)
{
    /* Arrange */
    reset_plants();

    /* Act */
    int result = plant_exists(MAX_PLANTS + 1);

    /* Assert */
    if (result)
        printf("FAILURE: test_plant_exists_error - non-existent ID returned 1\n");
    assert(!result);

    printf("OK: test_plant_exists_error\n");
}

/* 3 - Test Suite for update_last_watering() */

void test_update_last_watering_normal(void)
{
    /* Arrange */
    reset_plants();
    add_plant("name", "species", "01/01/2026", 10);

    /* Act */
    int result = update_last_watering(1, 10);

    /* Assert */
    if (!result)
    {
        printf("FAILURE: test_update_last_watering_normal - expected return 1, got %d\n", result);
    }
    assert(result);

    int last_watering = get_last_watering(1);
    if (last_watering != 10)
        printf("FAILURE: test_update_last_watering_normal - expected last_watering 10, got %d\n", last_watering);
    assert(last_watering == 10);

    printf("OK: test_update_last_watering_normal\n");
}

void test_update_last_watering_limit(void)
{
    /* Arrange */
    reset_plants();

    for (int i = 0; i < MAX_PLANTS; i++)
    {
        add_plant("name", "species", "01/01/2026", 10);
    }

    /* Act */
    int result = update_last_watering(MAX_PLANTS, 10);
    /* Assert */
    if (!result)
    {
        printf("FAILURE: test_update_last_watering_limit - expected return 1, got %d\n", result);
    }
    assert(result);

    int last_watering = get_last_watering(MAX_PLANTS);
    if (last_watering != 10)
        printf("FAILURE: test_update_last_watering_limit - expected last_watering 10, got %d\n", last_watering);
    assert(last_watering == 10);

    printf("OK: test_update_last_watering_limit\n");
}

void test_update_last_watering_error(void)
{
    /* Arrange */
    reset_plants();

    /* Act */
    int result = update_last_watering(MAX_PLANTS + 1, 10);

    /* Assert */
    if (result)
        printf("FAILURE: test_update_last_watering_error - non-existent ID returned 1\n");
    assert(!result);

    printf("OK: test_update_last_watering_error\n");
}

int main(void)
{
    printf("\n=== RUNNING TESTS: PLANTS MODULE ===\n");
    test_add_plant_normal();
    test_add_plant_limit();
    test_add_plant_error();
    test_plant_exists_normal();
    test_plant_exists_limit();
    test_plant_exists_error();
    test_update_last_watering_normal();
    test_update_last_watering_limit();
    test_update_last_watering_error();
    printf("=========================================\n");
    return 0;
}