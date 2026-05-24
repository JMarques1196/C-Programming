#include <stdio.h>
#include <stdlib.h>
#include "../include/types.h"    // Access to type definitions
#include "../include/data.h"     // Access to data loading and saving functions
#include "../include/plants.h"   // Access to plant-related functions
#include "../include/watering.h" // Access to watering-related functions
#include "../include/tasks.h"    // Access to task-related functions

int main(void)
{
    load_data();

    int option;
    printf("Welcome to the plant management system!\n");

    /* MENU */
    do
    {
        printf("1. List plants\n");
        printf("2. Add plant\n");
        printf("3. List waterings\n");
        printf("4. Add watering\n");
        printf("5. List tasks\n");
        printf("6. Add task\n");
        printf("7. Complete task\n");
        printf("8. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &option);

        switch (option)
        {
        /*
            List Plants - Option 1
            All saved plants are shown to the user
        */
        case 1:
        {
            printf("\n=== PLANT LIST ===\n");
            list_plants();
            printf("Press Enter to return to the main Menu... ");
            getchar(); // Clear the keyboard buffer
            getchar();
            break;
        }

        /*
            Add Plants - Option 2
            Receives data from the user and saves a new plant
        */
        case 2:
        {
            printf("\n=== ADD PLANTS ===\n");
            getchar();

            char name[50], species[50], planting_date[11];
            int watering_interval; /* in days */

            printf("Enter Name: ");
            fgets(name, sizeof(name), stdin);
            name[strcspn(name, "\n")] = '\0';

            printf("Enter Species: ");
            fgets(species, sizeof(species), stdin);
            species[strcspn(species, "\n")] = '\0';

            printf("Enter Planting Date (DD/MM/YYYY): ");
            fgets(planting_date, sizeof(planting_date), stdin);
            planting_date[strcspn(planting_date, "\n")] = '\0';

            printf("Enter Watering Interval (in days): ");
            scanf("%d", &watering_interval);

            add_plant(name, species, planting_date, watering_interval);
            printf("Plant added successfully!\n");
            save_data();
            break;
        }

        /*
            Check Watering Necessity - Option 3
            Given a current date by the user, checks the watering needs for that plant
        */
        case 3:
        {
            printf("\n=== CHECK WATERING NECESSITY ===\n");
            int current_date;

            printf("Current date (days since 01/01/2026): ");
            scanf("%d", &current_date);
            check_watering(current_date);

            printf("Press Enter to return to the main Menu... ");
            getchar();
            getchar();
            break;
        }

        /*
            Add Watering - Option 4
            Uses data received from the user (id, date, and quantity) to register a new watering
        */
        case 4:
        {
            printf("\n=== ADD WATERING ===\n");
            int plant_id, date, quantity;

            printf("Plant ID: ");
            scanf("%d", &plant_id);

            printf("Watering date (days since 01/01/2026): ");
            scanf("%d", &date);

            printf("Water quantity (in ml): ");
            scanf("%d", &quantity);

            getchar(); // Clear the keyboard buffer, which was missing
            register_watering(plant_id, date, quantity);
            save_data();
            break;
        }

        /*
            List Tasks - Option 5
            Provides the user with a list of all pending tasks, if any exist
        */
        case 5:
        {
            list_pending_tasks();
            printf("Press Enter to return to the main Menu... \n");
            getchar();
            getchar();
            break;
        }

        /*
            Add Task - Option 6
            Registers a new task using data provided by the user (description and due_date)
        */
        case 6:
        {
            printf("\n=== ADD TASK ===\n");
            getchar();

            char description[100];
            int due_date;

            printf("Task description: ");
            fgets(description, sizeof(description), stdin);
            description[strcspn(description, "\n")] = '\0';

            printf("Due date (days since 01/01/2026): ");
            scanf("%d", &due_date);

            create_task(description, due_date);
            save_data();
            break;
        }

        /*
            Complete Task - Option 7
            Allows tasks to be marked as completed
        */
        case 7:
        {
            printf("\n=== COMPLETE TASK ===\n");
            int id;

            printf("ID of the task to complete: ");
            scanf("%d", &id);

            complete_task(id);
            getchar();
            save_data();
            break;
        }

        case 8:
        {
            printf("Exiting the system. Goodbye!\n");
            return 0;
        }

        default:
        {
            printf("Invalid option. Please try again.\n");
        }
        }
    } while (option != 8);

    return 0;
}