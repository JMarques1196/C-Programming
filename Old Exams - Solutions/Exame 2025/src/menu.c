#include <stdio.h>
#include <stdlib.h>
#include "../include/menu.h"
#include "../include/files.h"
#include "../include/posts.h"

// Auxiliary function to clear the input buffer

void menu_run(PostList *list)
{
    int option = -1;

    do
    {

        printf("\n====================================\n");
        printf("       POSTS MANAGER   \n");
        printf("====================================\n");
        printf("1. List All Posts\n");
        printf("2. Load Popularity File\n");
        printf("0. Exit\n");
        printf("------------------------------------\n");
        printf("Select an option: ");

        scanf("%d", &option);
        getchar(); // Clear the input buffer

        switch (option)
        {
        case 1:
            post_list_display(list);
            printf("\nPress return to continue...");
            getchar();
            break;
        case 2:
            /* Load popularity file */
            printf("\nWIP\n");
            break;
        case 0:
            printf("\nExiting the program...\n");
            break;
        default:
            printf("\n[Warning] Invalid option! Please try again.\n");
            break;
        }

    } while (option != 0);
}