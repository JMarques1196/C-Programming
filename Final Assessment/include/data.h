/**
 * data.h - Aggregated persistence interface for the GreenTrack system.
 *
 * Provides a single entry point to load and save
 * all system data.
 */

#ifndef DATA_H
#define DATA_H

/**
 * Loads all system data from the CSV files.
 *
 * @note Calls load_plants(), load_waterings(), and load_tasks().
 */
void load_data(void);

/**
 * Saves all system data to the CSV files.
 *
 * @note Calls save_plants(), save_waterings(), and save_tasks().
 */
void save_data(void);

#endif