/**
 * data.c - Coordination of data persistence for the GreenTrack system.
 *
 * Aggregates loading and saving operations from all modules,
 * providing a single entry point for persistence.
 */

#include "../include/data.h"
#include "../include/plants.h"
#include "../include/watering.h"
#include "../include/tasks.h"

void load_data(void)
{
    load_plants();
    load_waterings();
    load_tasks();
}

void save_data(void)
{
    save_plants();
    save_waterings();
    save_tasks();
}