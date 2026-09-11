#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/types.h"
#include "../include/posts.h"

struct Post
{
    int id;
    char description[MAX_DESCRIPTION];
    char name[MAX_NAME];
    char category[MAX_CATEGORY];
    int views;
    int likes;
    int comments;
    float score;
};

struct PostList
{
    Post Elements[MAX_POSTS];
    int count;
};

/* Create and Destoy Lists */
PostList *post_list_create(void)
{
    PostList *list = (PostList *)malloc(sizeof(PostList));
    if (list != NULL)
    {
        list->count = 0;
    }
    return list;
}

/* Brief Note about pointer usage:
* In C, all function arguments are passed by value (a copy of the original). If we pass a
struct like PostList without using a pointer (*list), we would only be modifying the copy and not the actual
struct. While this only seems important for functions that actually want to modify data, using pointers in functions
that for instance, only display data, is a best practice. While those function would work by receing data by value,
they would be inneficient as we would be making a copy of the original data. While this might seem insignificant on smaller projects
, on larger project it could lead to a large waste of memory.
When using pointers in functions that do not modify data, it is best to set the struct as const
*/

void post_list_destroy(PostList *list)
{
    if (list != NULL)
    {
        free(list);
    }
}

/* Add a new post to the list
 Guard Clauses are used to check for NULL pointers and ensure that the list has not reached its maximum capacity.
 List is initiated in main.c
*/
Status post_list_add(PostList *list, int id, const char *description, const char *name, const char *category)
{

    if (list == NULL || description == NULL || name == NULL || category == NULL)
    {
        return FAIL;
    }
    if (list->count >= MAX_POSTS)
    {
        return FAIL;
    }

    int i = list->count;
    /* Logic:
        sctrncpy works as follows: (destination, source, size)
        sctrncpy does not add /0 at the end of the string, so we need to manually add it to ensure that the string is properly terminated.
    */
    list->Elements[i].id = id;
    strncpy(list->Elements[i].description, description, MAX_DESCRIPTION - 1);
    list->Elements[i].description[MAX_DESCRIPTION - 1] = '\0';

    strncpy(list->Elements[i].name, name, MAX_NAME - 1);
    list->Elements[i].name[MAX_NAME - 1] = '\0';

    strncpy(list->Elements[i].category, category, MAX_CATEGORY - 1);
    list->Elements[i].category[MAX_CATEGORY - 1] = '\0';

    // Inicializar métricas a zero
    list->Elements[i].views = 0;
    list->Elements[i].likes = 0;
    list->Elements[i].comments = 0;

    // 3. Incrementar o contador e retornar sucesso
    list->count++;
    return SUCCESS;
}

Status post_list_display(const PostList *list)
{
    if (list == NULL || list->count == 0)
    {
        printf("\n[Warning] No posts to display.\n");
        return FAIL;
    }

    printf("\n=================== ALL POSTS (%d) ===================\n", list->count);
    for (int i = 0; i < list->count; i++)
    {
        printf("ID: %d | Category: %s\n", list->Elements[i].id, list->Elements[i].category);
        printf("Name: %s\n", list->Elements[i].name);
        printf("Description: %s\n", list->Elements[i].description);
        printf("Metrics: %d Views | %d Likes | %d Comments\n",
               list->Elements[i].views, list->Elements[i].likes, list->Elements[i].comments);
        printf("-----------------------------------------------------------\n");
    }
    return SUCCESS;
}

Status post_list_update(PostList *list, int id, int views, int likes, int comments)
{
    /* score formula: = (0.5 * gostos + 0.3 * comentários + 0.2 * visualizações) / 100 */
    if (list == NULL)
    {
        return FAIL;
    }
    if (id < 0)
    {
        return FAIL;
    }
    /* Brief note about arrouw notation:
     * It is used to access a pointer to a struct
     * If we were working with the struct directly, we would use a dot (.) instead.
     */
    for (int i = 0; i < list->count; i++)
    {
        if (list->Elements[i].id == id)
        {
            list->Elements[i].views = views;
            list->Elements[i].likes = likes;
            list->Elements[i].comments = comments;
            list->Elements[i].score = (0.5 * likes + 0.3 * comments + 0.2 * views) / 100;
            return SUCCESS;
        }
    }
    return FAIL;
}

Status post_display(const PostList *list, int id)
{
    if (list == NULL || list->count == 0)
    {
        return FAIL;
    }
    printf("\n=================== POST FOUND ===================\n");
    for (int i = 0; i < list->count; i++)
    {
        if (list->Elements[i].id == id)
        {
            printf("ID: %d | Category: %s\n", list->Elements[i].id, list->Elements[i].category);
            printf("Name: %s\n", list->Elements[i].name);
            printf("Description: %s\n", list->Elements[i].description);
            printf("Metrics: %d Views | %d Likes | %d Comments\n",
                   list->Elements[i].views, list->Elements[i].likes, list->Elements[i].comments);
            printf("-----------------------------------------------------------\n");
        }
    }
    return SUCCESS;
}

Status post_edit(PostList *list, int id, const char *description, const char *name, const char *category)
{

    if (list == NULL || id <= 0 || description == NULL || name == NULL || category == NULL)
    {
        return FAIL;
    }

    for (int i = 0; i < list->count; i++)
    {
        if (list->Elements[i].id == id)
        {
            /* Brief note about strncpy:
            If, for instance, a name is larger than max description, the strncpy will fill the target array with characters, leaving no \0 in the end.
            The workaround used in this solution is to make strncpy only copy n-1 elements. We then manually add a \0 at the end.
            Without the null termination (\0), the program could print trash from the memory or even cause issues such as segfaults or crashes.
            */
            strncpy(list->Elements[i].description, description, MAX_DESCRIPTION - 1);
            list->Elements[i].description[MAX_DESCRIPTION - 1] = '\0';

            strncpy(list->Elements[i].name, name, MAX_NAME - 1);
            list->Elements[i].name[MAX_NAME - 1] = '\0';

            strncpy(list->Elements[i].category, category, MAX_CATEGORY - 1);
            list->Elements[i].category[MAX_CATEGORY - 1] = '\0';

            return SUCCESS; // Post encontrado e atualizado com sucesso
        }
    }

    printf("No post matches the provided ID\n");
    return FAIL;
};

Status post_remove(PostList *list, int id)
{
    /* logic:
        - find id of the post to remove
        - if the id is found, shift everything left
            - for i, i<count-1 i++
            - list->elements i = elemnts i+1, etc
        - reduce count
    */
    if (list == NULL || id <= 0 || list->count == 0)
    {
        return FAIL;
    }

    for (int i = 0; i <= list->count - 1; i++)
    {
        if (list->Elements[i].id == id)
        {
            while (i < list->count - 1)
            {
                list->Elements[i] = list->Elements[i + 1];
                i++;
            }
            list->count--;
            return SUCCESS;
        }
    }

    /* Failed to find id */
    return FAIL;
};

/* Auxiliary Functions */

Status update_by_score(PostList *list)

{
    //
}

/* GET SETTERS */
/* Esposes the post counter
 * This is a compromise between encapsulated code and the requirement to read an id from CSV files
 */
Status post_list_get_count(const PostList *list)
{
    if (list == NULL)
    {
        return FAIL;
    }
    return list->count;
}