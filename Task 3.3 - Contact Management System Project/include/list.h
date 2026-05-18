#ifndef LIST_H
#define LIST_H
#include "contact.h"

#define MAX_CONTACTS 100

typedef struct
{
    int count;
    Contact contacts[MAX_CONTACTS]; // Assuming a maximum of MAX_CONTACTS contacts for simplicity
} List;

int list_add_contact(Contact *contact, List *list);
int list_all_contacts(List *list);
int list_search_contact(const char *name, List *list);

#endif /* LIST_H */