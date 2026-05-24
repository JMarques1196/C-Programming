/**
 * tasks.h
 * Definition of the public interface for task management.
 */

#ifndef TASKS_H
#define TASKS_H

#include "../include/types.h"

/**
 * Creates and registers a new task in the system.
 *
 * @param description   Descriptive text of the task. Should not be NULL.
 * @param due_date      Deadline/scheduled date for the task execution.
 *
 * @return int 1 if the task was successfully created;
 *             0 if the maximum limit (MAX_TASKS) has been reached.
 *
 * @note Side effect: Modifies the internal array of tasks and increments the global counter.
 */
int create_task(char *description, int due_date);

/**
 * Lists all tasks that have not yet been completed.
 *
 * Iterates through the history in memory and prints to stdout the tasks whose
 * completion status is equal to zero.
 */
void list_pending_tasks(void);

/**
 * Marks a specific task as completed.
 *
 * Searches for the task by its unique identifier. If found, changes
 * its internal completion status.
 *
 * @param id Unique identifier of the task to complete.
 */
void complete_task(int id);

/**
 * Saves all tasks to the "tasks.csv" file.
 *
 * @return 1 if the file was successfully written.
 *         0 if the file could not be opened for writing.
 */
int save_tasks(void);

/**
 * Loads tasks from the "tasks.csv" file.
 *
 * @return 1 if the file was successfully read.
 *         0 if the file could not be opened.
 */
int load_tasks(void);

/**
 * Resets the counter and internal state of tasks to zero.
 * Used exclusively for testing purposes.
 */
void reset_tasks(void);

/*
 * Gets a task by its ID.
 * Used exclusively for testing purposes.
 */
Task get_task(int id);

#endif /* TASKS_H */