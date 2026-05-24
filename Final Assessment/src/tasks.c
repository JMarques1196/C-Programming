#include "../include/tasks.h"
#include "../include/types.h"
#include <stdio.h>
#include <string.h>

/*
    Counter and static array based on the defined PascalCase type.
    Data is private and encapsulated within the module.
*/
static int total_tasks = 0;
static Task tasks[MAX_TASKS];

/*
    Generates a sequential ID based on the accumulated history.
*/
static int generate_task_id(void)
{
    return total_tasks + 1;
}

int create_task(char *description, int due_date)
{

    if (total_tasks >= MAX_TASKS)
    {
        return 0;
    }
    if (description == NULL || due_date < 0)
    {
        return 0;
    }

    tasks[total_tasks].task_id = generate_task_id();
    strncpy(tasks[total_tasks].description, description, sizeof(tasks[total_tasks].description) - 1);
    tasks[total_tasks].description[sizeof(tasks[total_tasks].description) - 1] = '\0'; // Guarantee null-termination
    tasks[total_tasks].due_date = due_date;
    tasks[total_tasks].completed = 0;
    total_tasks++;

    /* printf("Task created successfully!\n");
        remove these prints to prevent output pollution during unit testing.
    */
    return 1;
}

void list_pending_tasks(void)
{

    if (total_tasks == 0)
    {
        printf("There are no registered tasks.\n");
        return;
    }
    for (int i = 0; i < total_tasks; i++)
    {

        if (tasks[i].completed == 0)
        {
            printf("Task %d: %s (due: %d)\n",
                   tasks[i].task_id, tasks[i].description,
                   tasks[i].due_date);
        }
    }
}

void complete_task(int id)
{
    for (int i = 0; i < total_tasks; i++)
    {
        if (tasks[i].task_id == id)
        {
            tasks[i].completed = 1;
            printf("Task completed successfully!\n");
            return;
        }
    }
    printf("Task not found.\n");
}

int save_tasks(void)
{
    FILE *f_tasks = fopen("tasks.csv", "w");
    if (f_tasks == NULL)
    {
        return 0;
    }
    for (int i = 0; i < total_tasks; i++)
    {
        fprintf(f_tasks, "%d,%s,%d,%d\n",
                tasks[i].task_id,
                tasks[i].description,
                tasks[i].due_date,
                tasks[i].completed);
    }
    fclose(f_tasks);
    return 1;
}

int load_tasks(void)
{

    FILE *f_tasks = fopen("tasks.csv", "r");
    if (f_tasks == NULL)
    {
        return 0;
    }

    total_tasks = 0;
    while (fscanf(f_tasks, "%d,%99[^,],%d,%d\n",
                  &tasks[total_tasks].task_id,
                  tasks[total_tasks].description,
                  &tasks[total_tasks].due_date,
                  &tasks[total_tasks].completed) == 4)
    {

        total_tasks++;

        if (total_tasks >= MAX_TASKS)
        {
            printf("Warning: Task limit reached while loading data.\n");
            break;
        }
    }

    fclose(f_tasks);
    return 1;
}

/********** Auxiliary Functions for Testing **********/
void reset_tasks(void) { total_tasks = 0; }
Task get_task(int id)
{
    for (int i = 0; i < total_tasks; i++)
    {
        if (tasks[i].task_id == id)
        {
            return tasks[i];
        }
    }
    Task empty_task = {0};
    return empty_task;
}