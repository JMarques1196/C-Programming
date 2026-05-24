#include "../include/types.h"
#include "../include/tasks.h"
#include <stdio.h>
#include <assert.h>

void test_create_task_normal(void)
{
    reset_tasks();

    int result = create_task("Water plants", 10);

    if (!result)
    {
        printf("FAILURE: valid task was not created\n");
    }

    assert(result);

    printf("OK: test_create_task_normal\n");
}

void test_create_task_limit(void)
{
    reset_tasks();

    for (int i = 0; i < MAX_TASKS; i++)
    {
        create_task("Task", 10);
    }

    int result = create_task("Extra", 10);

    if (result)
    {
        printf("FAILURE: allowed creating task above the limit\n");
    }

    assert(!result);

    printf("OK: test_create_task_limit\n");
}

void test_create_task_error(void)
{
    reset_tasks();

    int result = create_task(NULL, 10);

    if (result)
    {
        printf("FAILURE: task created with NULL description\n");
    }

    assert(!result);

    printf("OK: test_create_task_error\n");
}

int main(void)
{
    printf("\n=== RUNNING TESTS: TASKS MODULE ===\n");
    test_create_task_normal();
    test_create_task_limit();
    test_create_task_error();
    printf("=========================================\n");
    return 0;
}