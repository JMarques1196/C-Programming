/* Add, list and search contacts */
#include "../include/list.h"
#include "../include/contact.h"
#include <stddef.h>
#include <string.h>
#include <stdio.h>

int list_add_contact(Contact *contact, List *list)
{
    // Add contact to list
    if (contact == NULL || list == NULL)
    {
        return 0; // Return 0 for failure
    }
    if (list->count >= MAX_CONTACTS)
    {
        printf("Contact list is full!\n");
        return 0; // Return 0 for failure
    }
    list->contacts[list->count] = *contact; // Add contact to list
    list->count++;                          // Increment contact count

    return 1; // Return 1 for success
}
int list_all_contacts(List *list)
{
    // List all contacts
    if (list == NULL)
    {
        return 0;
    }

    for (int i = 0; i < list->count; i++)
    {
        contact_display(&list->contacts[i]); // We use & to get the address of the contact in the list, since contact_display expects a pointer
    }

    return 1; // Return 1 for success
}

int list_search_contact(const char *name, List *list)
{
    // Search for contact by name
    char found = 0; // Flag to indicate if contact is found
    if (list == NULL || name == NULL)
    {
        return 0;
    }

    for (int i = 0; i < list->count; i++)
    {
        if (strcmp(list->contacts[i].name, name) == 0)
        {                                        // Compare contact name with search name
            contact_display(&list->contacts[i]); // Display contact if found
            found = 1;                           // Set flag to indicate contact is found
            break;                               // Exit loop after finding the contact
        }
    }

    if (!found)
    {
        printf("Contact not found!\n");
        return 0; // Return 0 for failure
    }

    return 1; // Return 1 for success
}
