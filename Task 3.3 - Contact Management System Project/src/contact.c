/* Functions to implement:
    * - contact_init
    * - contact_set_name
    * - contact_set_phone
    * - contact_print

    Calls validate functions for phone number and email
*/

#include "../include/contact.h"
#include "../include/validation.h"
#include <stdio.h>
#include <string.h>

int contact_init(Contact *contact) // We need this pointer so the result outlives the function scope
{
    printf("Enter name: ");
    fgets(contact->name, sizeof(contact->name), stdin); // Arrow notation to access struct members through a pointer
    contact->name[strcspn(contact->name, "\n")] = 0;    // Remove newline character if present
    printf("Enter phone: ");
    fgets(contact->phone, sizeof(contact->phone), stdin);
    contact->phone[strcspn(contact->phone, "\n")] = 0;
    printf("Enter email: ");
    fgets(contact->email, sizeof(contact->email), stdin);
    contact->email[strcspn(contact->email, "\n")] = 0;

    return contact_validate(contact);
}

void contact_display(Contact *contact)
{
    printf("Name: %s\n", contact->name);
    printf("Phone: %s\n", contact->phone);
    printf("Email: %s\n", contact->email);
}

int contact_validate(Contact *contact)
{
    if (!validate_phone(contact->phone))
    {
        printf("Invalid phone number!\n");
        return 0; // Return 0 for failure
    }
    if (!validate_email(contact->email))
    {
        printf("Invalid email address!\n");
        return 0; // Return 0 for failure
    }
    return 1; // Return 1 for success
}
