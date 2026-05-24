#include <assert.h>
#include <stdio.h>
#include <string.h>
#include "../include/plants.h"
#include "../include/watering.h"
#include "../include/tasks.h"
#include "../include/data.h"

/* Integration Test - Data Persistence - Interaction of save_plants + load_plants with the file system */
void test_plants_integration(void)
{
    /* Arrange */
    remove("plants.csv");
    reset_plants();
    char name[50] = "test", species[50] = "test_species", planting_date[11] = "01/01/2026";
    int watering_interval = 10; /* in days */

    /* Act */
    add_plant(name, species, planting_date, watering_interval);
    save_plants();
    reset_plants();
    load_plants();
    Plant persisted_data = get_plant(1);

    /* Assert */
    if (persisted_data.id != 1)
    {
        printf("Error: Wrong Id\n");
        assert(persisted_data.id == 1);
    }
    if (strcmp(persisted_data.name, "test") != 0)
    {
        printf("Error: wrong name\n");
        assert(strcmp(persisted_data.name, "test") == 0);
    }
    if (strcmp(persisted_data.species, "test_species") != 0)
    {
        printf("Error: wrong species\n");
        assert(strcmp(persisted_data.species, "test_species") == 0);
    }
    if (strcmp(persisted_data.planting_date, "01/01/2026") != 0)
    {
        printf("Error: wrong planting_date\n");
        assert(strcmp(persisted_data.planting_date, "01/01/2026") == 0);
    }
    if (persisted_data.watering_interval != 10)
    {
        printf("Error: wrong watering_interval\n");
        assert(persisted_data.watering_interval == 10);
    }

    printf("OK: Plants integration test\n");
}

/* Integration Test - Logic between modules - Verifies that register_watering() correctly updates the last_watering field in the plants module */
void test_waterings_integration(void)
{
    /* Arrange */
    reset_waterings();
    reset_plants();

    int plant_id = 1, date = 10, quantity = 500;
    char name[50] = "test", species[50] = "test_species", planting_date[11] = "01/01/2026";
    int watering_interval = 10; /* in days */

    /* Act */
    add_plant(name, species, planting_date, watering_interval);
    register_watering(plant_id, date, quantity);

    /* Assert */
    int last_watering = get_last_watering(plant_id);
    if (last_watering != date)
    {
        printf("Error: last watering not updated correctly\n");
        assert(last_watering == date);
    }

    printf("OK: Waterings integration test\n");
}

void test_data_integration(void)
{
    /* Arrange */
    remove("plants.csv");
    remove("tasks.csv");
    remove("waterings.csv");

    reset_plants();
    reset_waterings();
    reset_tasks();

    char name[50] = "test", species[50] = "test_species", planting_date[11] = "01/01/2026";
    int watering_interval = 10;
    int plant_id = 1, date = 10, quantity = 500;
    char description[100] = "Pruning";
    int due_date = 10;

    /* Act */
    add_plant(name, species, planting_date, watering_interval);
    register_watering(plant_id, date, quantity);
    create_task(description, due_date);

    save_data();
    reset_plants();
    reset_waterings();
    reset_tasks();
    load_data();

    Plant persisted_data = get_plant(1);
    Task persisted_task = get_task(1);
    Watering persisted_watering = get_registered_watering(1);

    /* Assert */
    if (persisted_data.id != 1)
    {
        printf("Error: Wrong Id\n");
        assert(persisted_data.id == 1);
    }
    if (strcmp(persisted_data.name, "test") != 0)
    {
        printf("Error: wrong name\n");
        assert(strcmp(persisted_data.name, "test") == 0);
    }
    if (strcmp(persisted_data.species, "test_species") != 0)
    {
        printf("Error: wrong species\n");
        assert(strcmp(persisted_data.species, "test_species") == 0);
    }
    if (strcmp(persisted_data.planting_date, "01/01/2026") != 0)
    {
        printf("Error: wrong planting_date\n");
        assert(strcmp(persisted_data.planting_date, "01/01/2026") == 0);
    }
    if (persisted_data.watering_interval != 10)
    {
        printf("Error: wrong watering_interval\n");
        assert(persisted_data.watering_interval == 10);
    }

    if (persisted_task.task_id != 1)
    {
        printf("Error: Wrong task Id\n");
        assert(persisted_task.task_id == 1);
    }
    if (strcmp(persisted_task.description, "Pruning") != 0)
    {
        printf("Error: wrong task description\n");
        assert(strcmp(persisted_task.description, "Pruning") == 0);
    }
    if (persisted_task.due_date != 10)
    {
        printf("Error: wrong task due_date\n");
        assert(persisted_task.due_date == 10);
    }
    if (persisted_task.completed != 0)
    {
        printf("Error: wrong task completed status\n");
        assert(persisted_task.completed == 0);
    }

    if (persisted_watering.plant_id != 1)
    {
        printf("Error: Wrong watering plant Id\n");
        assert(persisted_watering.plant_id == 1);
    }
    if (persisted_watering.watering_date != 10)
    {
        printf("Error: wrong watering date\n");
        assert(persisted_watering.watering_date == 10);
    }
    if (persisted_watering.water_quantity != 500)
    {
        printf("Error: wrong watering water quantity\n");
        assert(persisted_watering.water_quantity == 500);
    }

    printf("OK: Data integration test\n");
}

int main(void)
{
    printf("\n=== RUNNING INTEGRATION TESTS ===\n");
    test_plants_integration();
    test_waterings_integration();
    test_data_integration();
    printf("=========================================\n");
    return 0;
}