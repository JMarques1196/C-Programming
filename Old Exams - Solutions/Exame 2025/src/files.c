#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/types.h"
#include "../include/posts.h"
#include "../include/files.h"

Status file_load_posts(const char *filename, PostList *list)
{

    FILE *fp = fopen(filename, "r");

    if (!fp)
    {
        return FAIL;
    }

    int total_posts = 0;
    int temporary_id = 0;
    char temporary_name[MAX_NAME];
    char temporary_category[MAX_CATEGORY];
    char temporary_description[MAX_DESCRIPTION];

    while (total_posts < MAX_POSTS &&
           fscanf(fp, "%d,%49[^,],%29[^,],%511[^\n]",
                  &temporary_id,
                  temporary_name,
                  temporary_category,
                  temporary_description) == 4)
    {

        post_list_add(list, temporary_id, temporary_description, temporary_name, temporary_category);
        total_posts++;
    }

    fclose(fp);
    return SUCCESS;
}
