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
        printf("\n[Aviso] Nao ha posts para exibir.\n");
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

Status post_list_update_metrics(PostList *list, int id, int views, int likes, int comments);