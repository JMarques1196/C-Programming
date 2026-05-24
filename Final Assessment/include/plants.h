#ifndef PLANTS_H
#define PLANTS_H
#include "../include/types.h"

/**
 * Lists all plants registered in the system.
 *
 * Iterates through the global array of plants and prints the details
 * of each one to the terminal. If no plants exist, prints an
 * informative message.
 *
 * @note Side effect: writes directly to stdout.
 */
void list_plants(void);

/**
 * Adds a new plant to the system.
 *
 * @param name          Common name of the plant. Cannot be NULL.
 * @param species       Scientific name of the species. Cannot be NULL.
 * @param planting_date Planting date in "DD/MM/YYYY" format. Cannot be NULL.
 * @param interval      Watering interval in days. Must be greater than 0.
 *
 * @return 1 if the plant was successfully added.
 *         0 if the maximum number of plants (MAX_PLANTS) was reached.
 *
 * @note Side effect: modifies the global array of plants and increments total_plants.
 */
int add_plant(char *name, char *species, char *planting_date, int interval);

/**
 * Saves all plants to the "plants.csv" file.
 *
 * Each line of the file follows the format:
 * id,name,species,planting_date,watering_interval,last_watering
 *
 * @return 1 if the file was successfully written.
 *         0 if the file could not be opened for writing.
 *
 * @note Side effect: overwrites the existing "plants.csv" file.
 */
int save_plants(void);

/**
 * Loads plants from the "plants.csv" file.
 *
 * Reads the file line by line, expecting the format:
 * id,name,species,planting_date,watering_interval,last_watering
 *
 * Reading stops when the end of file is reached or when
 * the MAX_PLANTS limit is reached.
 *
 * @return 1 if the file was successfully read.
 *         0 if the file could not be opened.
 *
 * @note Side effect: overwrites the global array of plants
 *       and resets total_plants to 0 before loading.
 */
int load_plants(void);

/**
 * Checks and lists the plants that need watering.
 *
 * A plant needs watering when the number of days since
 * the last watering is equal to or greater than its watering interval.
 *
 * @param current_date Current day in days since 01/01/2026. Must be >= 0.
 *
 * @note Side effect: writes directly to stdout.
 */
void check_watering(int current_date);

/**
 * Updates the last watering date of a plant.
 *
 * @param plant_id Identifier of the plant to update.
 * @param date     Watering day in days since 01/01/2026. Must be >= 0.
 *
 * @return 1 if the plant was found and successfully updated.
 *         0 if no plant exists with the provided id.
 *
 * @note Side effect: modifies the last_watering field in the global array of plants.
 */
int update_last_watering(int plant_id, int date);

/**
 * Checks if a plant with the provided identifier exists in the system.
 *
 * @param plant_id Identifier of the plant to search for.
 *
 * @return 1 if the plant exists.
 *         0 if no plant exists with the provided id.
 */
int plant_exists(int plant_id);

/**
 * Returns the current number of registered plants.
 * Used exclusively for testing purposes.
 */
int current_total_plants(void);

/**
 * Resets the counter and internal state of plants to zero.
 * Used exclusively for testing purposes.
 */
void reset_plants(void);

/**
 * Returns the last_watering value for the plant with the provided id.
 * Used exclusively for testing purposes.
 *
 * @param plant_id Identifier of the plant.
 * @return Value of last_watering, or 0 if the plant does not exist.
 */
int get_last_watering(int plant_id);

Plant get_plant(int plant_id);

#endif