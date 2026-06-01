// Orchestrator Function - No logic
#include "../include/types.h"
#include "../include/parser.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    /* Define Structure and Allocate Memory for Posts */
    Post *post = malloc(sizeof(Post) * MAX_POSTS);

    /* Verify Correct allocation */
    if (!post)
    {
        fprintf(stderr, "malloc failed\n");
        return 1;
    }

    /* Define Structure and Allocate Memory for Popularity */
    Popularity *popularity = malloc((sizeof(Popularity)) * MAX_POSTS);
    if (!popularity)
    {
        fprintf(stderr, "malloc failed\n");
        return 1;
    }

    /* Check if all files were provided */
    if (argc < 3)
    {
        printf("Usage: %s <posts.csv> <popularity.csv>\n", argv[0]);
        return 1; // Return 1 = Error
    }

    /* Parse CSVs  */
    post_parser(argv[1], post);
    popularity_parser(argv[2], popularity);

    /* Call organizer function */

    /* Diplay Menu */

    int selection;
    do
    {
        printf("Menu: \n");
        printf("1. Display all posts\n");
        printf("2. Exit\n");

        scanf("%d", &selection);

        switch (selection)
        {
        case 1:
            /* code */
            printf("Switch\n\n");

        case 2:
            break;
        }

    } while (selection != 2);

    free(post);
    free(popularity);

    return 0;
}