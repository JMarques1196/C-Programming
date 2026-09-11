#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/menu.h"
#include "../include/files.h"
#include "../include/posts.h"

// Auxiliary function to clear the input buffer
// ============================================================================
// PROTÓTIPOS PRIVADOS (Apenas visíveis dentro deste menu.c)
// ============================================================================
static void clear_buffer(void);
static void read_post_fields(char *name, char *description, char *category);
static int post_id_input(void);
static Status post_input(PostList *list);
static Status post_editor(PostList *list);

void menu_run(PostList *list)
{
    int option = -1;

    do
    {

        printf("\n====================================\n");
        printf("       POSTS MANAGER   \n");
        printf("====================================\n");
        printf("1. List All Posts\n");
        printf("2. Add new post\n");
        printf("3. Post Editor\n");
        printf("0. Exit\n");
        printf("------------------------------------\n");
        printf("Select an option: ");

        scanf("%d", &option);

        switch (option)
        {
        case 1:
            post_list_display(list);
            printf("\nPress return to continue...");
            getchar();
            break;
        case 2:
            /* Add new Post*/
            post_input(list);
            break;
        case 3:
            /* Post Editor */
            post_editor(list);
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

static Status post_input(PostList *list)
{

    if (!list)
    {
        return FAIL;
    }
    int id = post_list_get_count(list) + 1;
    char name[MAX_NAME];
    char description[MAX_DESCRIPTION];
    char category[MAX_CATEGORY];

    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;

    printf("-----New Post-----\n");

    read_post_fields(name, description, category);

    if (post_list_add(list, id, description, name, category))
    {
        printf("Sucessfully added a new Post\n");
        return SUCCESS;
    }
    else
    {
        printf("Error adding new post...\n");
        return FAIL;
    }
}

static Status post_editor(PostList *list)
{
    int option;
    int id;
    char name[MAX_NAME];
    char description[MAX_DESCRIPTION];
    char category[MAX_CATEGORY];

    do
    {
        printf("\n====================================\n");
        printf("       Welcome to the Post Editor   \n");
        printf("====================================\n");
        printf("1. Search Post\n");
        printf("2. Edit Post\n");
        printf("3. Remove Post\n");
        printf("0. Exit\n");
        printf("------------------------------------\n");
        printf("Select an option: ");

        scanf("%d", &option);

        switch (option)
        {
        case 1:
            id = post_id_input();
            post_display(list, id);
            printf("\nPress return to continue...");
            getchar();
            break;
        case 2:
            id = post_id_input();
            read_post_fields(name, description, category);
            if (post_edit(list, id, description, name, category) == SUCCESS)
            {
                printf("\nPost edited successfully.\n");
            }
            else
            {
                printf("\n[Error] Failed to edit the post. Please check the ID and try again.\n");
            }
            printf("\nPress return to continue...");
            getchar();
            break;
        case 3:
            id = post_id_input();
            post_remove(list, id);
            getchar();
            break;
        case 0:
            break;
        }
    } while (option != 0);
}

static int post_id_input(void)
{
    int id;
    printf("Enter the post ID:\n");
    scanf("%d", &id);
    // Clear the input buffer to avoid issues with subsequent input
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
    return id;
}

static void read_post_fields(char *name, char *description, char *category)
{
    printf("Name: ");
    if (fgets(name, MAX_NAME, stdin) != NULL)
        name[strcspn(name, "\r\n")] = '\0';

    printf("Description: ");
    if (fgets(description, MAX_DESCRIPTION, stdin) != NULL)
        description[strcspn(description, "\r\n")] = '\0';

    printf("Category: ");
    if (fgets(category, MAX_CATEGORY, stdin) != NULL)
        category[strcspn(category, "\r\n")] = '\0';
}