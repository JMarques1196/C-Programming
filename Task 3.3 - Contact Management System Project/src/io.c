#include "../include/io.h"
#include "../include/list.h"
#include <stdlib.h>
#include <stdio.h>

#define FILENAME "contacts.csv"

int io_write_contacts(List *list)
{
    FILE *file = fopen(FILENAME, "w");

    if (file == NULL)
    {
        perror("Error opening file for writing");
        return 0;
    }

    for (int i = 0; i < list->count; i++)
    {
        Contact *contact = &list->contacts[i];
        fprintf(file, "%s,%s,%s\n", contact->name, contact->phone, contact->email);
    }

    fclose(file);
    return 1;
}

int io_read_contacts(List *list)
{
    FILE *file = fopen(FILENAME, "r");

    if (file == NULL)
    {
        perror("Error opening file for reading");
        return 0;
    }

    char line[200];
    list->count = 0;

    while (fgets(line, sizeof(line), file) && list->count < MAX_CONTACTS)
    {
        Contact *contact = &list->contacts[list->count];
        sscanf(line, "%49[^,],%14[^,],%49[^\n]", contact->name, contact->phone, contact->email);
        list->count++;
    }

    fclose(file);
    return 1;
}