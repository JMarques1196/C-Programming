#include "../include/types.h"
#include "../include/parser.h"
#include <stdio.h>

int post_parser(char *file_name, Post *post)
{

    FILE *fp = fopen(file_name, "r");
    // guard clauses
    if (!fp)
    {
        return 0;
    }

    int total_posts = 0;

    while (total_posts < MAX_POSTS &&
           fscanf(fp, "%d,%49[^,],%29[^,],%511[^\n]",
                  &post[total_posts].id,
                  post[total_posts].name,
                  post[total_posts].category,
                  post[total_posts].description) == 4)
    {

        total_posts++;
    }

    fclose(fp);
    return total_posts;
}

/* Info from CSV regarding popularity should be equal to the number of posts in the Post CSV, otherwise posts will be missing data */
int popularity_parser(char *file_name, Popularity *popularity)
{

    FILE *fp = fopen(file_name, "r");
    // guard clauses
    if (!fp)
    {
        return 0;
    }

    int total_popularity_info = 0;

    while (total_popularity_info < MAX_POSTS &&
           fscanf(fp, "%d,%d,%d,%d",
                  &popularity[total_popularity_info].id,
                  &popularity[total_popularity_info].likes,
                  &popularity[total_popularity_info].number_of_comments,
                  &popularity[total_popularity_info].visualizations) == 4)

    {
        total_popularity_info++;
    }

    fclose(fp);
    return total_popularity_info;
}