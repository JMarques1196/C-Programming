#ifndef POSTS_H
#define POSTS_H

#include "types.h"

/* For this solution, opaque types were used
 To implement opaque types, forward declarations of the structures are provided in the header file, while the actual definitions are kept in the source file.
 This allows the implementation details to be hidden from the users of the library, promoting encapsulation and modularity.
*/
typedef struct Post Post;
typedef struct PostList PostList;

/* Create and Free the list */
PostList *post_list_create(void);
void post_list_destroy(PostList *list);

/* Add and Update Posts */
Status post_list_add(PostList *list, int id, const char *description, const char *name, const char *category);
Status post_list_update_metrics(PostList *list, int id, int views, int likes, int comments);

/* Display the list of posts */
Status post_list_display(const PostList *list);

#endif // POSTS_H