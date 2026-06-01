#ifndef TYPES_H
#define TYPES_H

#define MAX_NAME 50
#define MAX_CATEGORY_NAME 30
#define MAX_DESCRIPTION 500
#define MAX_POSTS 100

typedef struct
{
    int id;
    char name[MAX_NAME];
    char category[MAX_CATEGORY_NAME];
    char description[MAX_DESCRIPTION];
} Post;

typedef struct
{
    int id;
    int visualizations;
    int likes;
    int number_of_comments;
} Popularity;

#endif // TYPES_H