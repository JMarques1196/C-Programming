#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/types.h"
#include "../include/posts.h"

typedef struct {
    
} Post;

typedef struct {

} PostList;

Status post_list_add(PostList *list, int id, const char *description, const char *influencer, const char *category);
Status post_list_update_metrics(PostList *list, int id, int views, int likes, int comments);