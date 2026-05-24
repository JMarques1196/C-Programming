/**
 * @file watering.h
 * Definition of the public interface for watering registration and history.
 */

#ifndef WATERING_H
#define WATERING_H
#include "../include/types.h"

/**
 * Registers a new watering action in the system.
 *
 * Verifies the existence of the plant before registering. If successful,
 * the watering history is updated and the last watering state of the plant is modified.
 *
 * @param plant_id  Unique identifier of the plant to be watered.
 * @param date      Watering day (represented in days since 01/01/2026).
 * @param quantity  Amount of water applied (in milliliters or defined unit).
 *
 * @return int 1 if the watering was successfully registered;
 *             0 if the plant does not exist or if the maximum record limit is reached.
 *
 * @note Side effect: Modifies the internal array of waterings, increments the total counter
 *       and alters the corresponding plant state through the associated module.
 */
int register_watering(int plant_id, int date, int quantity);

/**
 * Saves the entire watering history to the "waterings.csv" file.
 *
 * Each line of the file follows the format:
 * watering_id,plant_id,watering_date,water_quantity
 *
 * @return int 1 if the file was successfully saved;
 *             0 if an error occurred while opening the file for writing.
 */
int save_waterings(void);

/**
 * Loads the watering history from the "waterings.csv" file.
 *
 * Reads records line by line. Reading is interrupted when the end of
 * the file is reached or when the MAX_WATERINGS limit is reached.
 *
 * @return int 1 if the file was successfully read;
 *             0 if the file could not be opened.
 *
 * @note Side effect: Clears the history in memory and resets the watering
 *       counter before starting to read.
 */
int load_waterings(void);

/**
 * Returns the current number of registered waterings.
 * Used exclusively for testing purposes.
 */
int current_total_waterings(void);

/**
 * Resets the counter and internal state of waterings to zero.
 * Used exclusively for testing purposes.
 */
void reset_waterings(void);

/**
 * Gets the last watering of a plant.
 * Used exclusively for testing purposes.
 */
Watering get_registered_watering(int plant_id);

#endif /* WATERING_H */