#ifndef POSTS_H
#define POSTS_H

#include "types.h"

/* For this solution, opaque types were used */
typedef struct Post Post;
typedef struct PostList PostList;

/* Create and Free the list */
PostList *post_list_create(void);
void post_list_destroy(PostList *list);

/* Add and Update Posts */
Status post_list_add(PostList *list, int id, const char *description, const char *influencer, const char *category);
Status post_list_update_metrics(PostList *list, int id, int views, int likes, int comments);

#endif // POSTS_H