#include "../include/plants.h"
#include "../include/types.h"
#include <stdio.h>
#include <string.h>

/*
    Private array and counter to the module — inaccessible directly by other files.
    External access is done exclusively through the public functions of this module.
*/
static Plant plants[MAX_PLANTS];
static int total_plants = 0;

/*
    Generates a sequential ID based on the current total of plants.
    Note: IDs are not reused after removing plants.
*/
static int generate_plant_id(void)
{
    return total_plants + 1;
}

/********** Public Functions **********/
void list_plants(void)
{
    if (total_plants == 0)
    {
        printf("There are no registered plants.\n");
        return;
    }
    for (int i = 0; i < total_plants; i++)
    {
        printf("ID: %d\n", plants[i].id);
        printf("  Name: %s\n", plants[i].name);
        printf("  Species: %s\n", plants[i].species);
        printf("  Planting date: %s\n", plants[i].planting_date);
        printf("  Watering interval: %d days\n", plants[i].watering_interval);
        printf("  Last watering: %d\n", plants[i].last_watering);
        printf("---------------------------------\n");
    }
}

int add_plant(char *name, char *species, char *planting_date, int interval)
{

    if (total_plants >= MAX_PLANTS)
    {
        return 0;
    }
    if (name == NULL || species == NULL || planting_date == NULL || interval < 1)
    {
        return 0;
    }
    plants[total_plants].id = generate_plant_id();

    /*
        strncpy does not guarantee null-termination if the source reaches the limit.
        The '\0' is manually forced to avoid non-terminated strings.
    */
    strncpy(plants[total_plants].name, name, sizeof(plants[total_plants].name) - 1);
    plants[total_plants].name[sizeof(plants[total_plants].name) - 1] = '\0';

    strncpy(plants[total_plants].species, species, sizeof(plants[total_plants].species) - 1);
    plants[total_plants].species[sizeof(plants[total_plants].species) - 1] = '\0';

    strncpy(plants[total_plants].planting_date, planting_date, sizeof(plants[total_plants].planting_date) - 1);
    plants[total_plants].planting_date[sizeof(plants[total_plants].planting_date) - 1] = '\0';

    plants[total_plants].watering_interval = interval;
    plants[total_plants].last_watering = 0;

    total_plants++;
    return 1;
}

int save_plants(void)
{
    FILE *f_plants = fopen("plants.csv", "w");
    if (f_plants == NULL)
    {
        return 0;
    }

    for (int i = 0; i < total_plants; i++)
    {
        fprintf(f_plants, "%d,%s,%s,%s,%d,%d\n",
                plants[i].id,
                plants[i].name,
                plants[i].species,
                plants[i].planting_date,
                plants[i].watering_interval,
                plants[i].last_watering);
    }
    fclose(f_plants);
    return 1;
}

int load_plants(void)
{
    FILE *f_plants = fopen("plants.csv", "r");
    if (f_plants == NULL)
    {
        return 0;
    }

    total_plants = 0;
    /*
        %[^,] reads up to the comma without consuming it, allowing parsing of the CSV format
        without the need for manual tokenization with strtok.
    */
    while (total_plants < MAX_PLANTS && fscanf(f_plants, "%d,%[^,],%[^,],%[^,],%d,%d\n",
                                               &plants[total_plants].id,
                                               plants[total_plants].name,
                                               plants[total_plants].species,
                                               plants[total_plants].planting_date,
                                               &plants[total_plants].watering_interval,
                                               &plants[total_plants].last_watering) == 6)
    {
        total_plants++;
    }

    fclose(f_plants);
    return 1;
}

void check_watering(int current_date)
{
    if (total_plants == 0)
    {
        printf("There are no registered plants.\n");
        return;
    }

    printf("=== PLANTS THAT NEED WATERING ===\n");
    for (int i = 0; i < total_plants; i++)
    {
        int days = current_date - plants[i].last_watering;
        if (days >= plants[i].watering_interval)
        {
            printf("Plant %s (ID: %d) needs watering! (last: %d days ago)\n",
                   plants[i].name, plants[i].id, days);
        }
    }
}

int update_last_watering(int plant_id, int date)
{
    for (int i = 0; i < total_plants; i++)
    {
        if (plants[i].id == plant_id)
        {
            plants[i].last_watering = date;
            return 1;
        }
    }
    return 0;
}

int plant_exists(int plant_id)
{
    for (int i = 0; i < total_plants; i++)
    {
        if (plants[i].id == plant_id)
        {
            return 1;
        }
    }
    return 0;
}

/********** Auxiliary Functions for Testing **********/
int current_total_plants(void) { return total_plants; }
void reset_plants(void) { total_plants = 0; }
int get_last_watering(int plant_id)
{
    for (int i = 0; i < total_plants; i++)
    {
        if (plants[i].id == plant_id)
        {
            return plants[i].last_watering;
        }
    }
    return 0;
}

Plant get_plant(int plant_id)
{
    for (int i = 0; i < total_plants; i++)
    {
        if (plants[i].id == plant_id)
        {
            return plants[i];
        }
    }

    Plant empty = {0};
    return empty;
}