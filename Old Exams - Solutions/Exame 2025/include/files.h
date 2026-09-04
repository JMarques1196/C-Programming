#ifndef FILES_H
#define FILES_H

// No include/files.h
Status file_load_posts(const char *filename, PostList *list);
Status file_load_popularity(const char *filename, PostList *list);

#endif // FILES_H