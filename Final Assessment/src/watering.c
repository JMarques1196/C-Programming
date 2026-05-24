#include <stdio.h>
#include "../include/watering.h"
#include "../include/plants.h"
#include "../include/types.h"

static Watering waterings[MAX_WATERINGS];
static int total_waterings = 0;

/********** Public Functions **********/

int register_watering(int plant_id, int date, int quantity)
{
    // Referential integrity validation: the plant must exist in the system
    if (!plant_exists(plant_id))
    {
        return 0;
    }

    // Protection against memory overflow (static array overflow)
    if (total_waterings >= MAX_WATERINGS)
    {
        return 0;
    }

    waterings[total_waterings].watering_id = total_waterings + 1;
    waterings[total_waterings].plant_id = plant_id;
    waterings[total_waterings].watering_date = date;
    waterings[total_waterings].water_quantity = quantity;
    total_waterings++;

    // State synchronization: updates the last watering marker on the plant record
    update_last_watering(plant_id, date);

    /* printf("Watering registered successfully for plant ID %d!\n", plant_id);
       remove these prints to prevent output pollution during unit testing.
   */
    return 1;
}

int save_waterings(void)
{
    FILE *f_waterings = fopen("waterings.csv", "w");
    if (f_waterings == NULL)
    {
        return 0;
    }

    for (int i = 0; i < total_waterings; i++)
    {
        fprintf(f_waterings, "%d,%d,%d,%d\n",
                waterings[i].watering_id,
                waterings[i].plant_id,
                waterings[i].watering_date,
                waterings[i].water_quantity);
    }
    fclose(f_waterings);
    return 1;
}

int load_waterings(void)
{
    FILE *f_waterings = fopen("waterings.csv", "r");
    if (f_waterings == NULL)
    {
        return 0;
    }

    total_waterings = 0;

    /*
        Avoids using !feof() by controlling flow directly through the fscanf return value
        combined with the array boundary protection.
    */
    while (total_waterings < MAX_WATERINGS && fscanf(f_waterings, "%d,%d,%d,%d\n",
                                                     &waterings[total_waterings].watering_id,
                                                     &waterings[total_waterings].plant_id,
                                                     &waterings[total_waterings].watering_date,
                                                     &waterings[total_waterings].water_quantity) == 4)
    {
        total_waterings++;
    }

    fclose(f_waterings);
    return 1;
}

/********** Auxiliary Functions for Testing **********/

int current_total_waterings(void) { return total_waterings; }
void reset_waterings(void) { total_waterings = 0; }
Watering get_registered_watering(int plant_id)
{

    for (int i = 0; i < total_waterings; i++)
    {
        if (waterings[i].plant_id == plant_id)
        {
            return waterings[i];
        }
    }

    Watering empty_watering = {0, 0, 0, 0};
    return empty_watering; // Returns an "empty" watering if no match is found
}