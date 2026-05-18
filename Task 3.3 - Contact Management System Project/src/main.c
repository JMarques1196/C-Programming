/*
Main will only contain the menu
No Logic will be implemented here
*/
#include <stdio.h>
#include <string.h>
#include "../include/io.h"
#include "../include/list.h"
#include "../include/contact.h"

int main(void)
{
    List contact_list;
    contact_list.count = 0;          // Initialize the contact list
    io_read_contacts(&contact_list); // Load contacts from file at startup
    int i = 0;
    char name[50];

    /*
        List - add list and search
        Contact - create, validate, display, edit, delete
        validation - helper functions for email and phone number validation
        io - reading and writing contacts to file
    */

    while (1)
    {
        printf("Sistema de Gestão de Contactos\n");
        printf("1 - Adicionar Contacto\n");
        printf("2 - Listar Contactos\n");
        printf("3 - Pesquisar Contacto\n");
        printf("0 - Sair\n");
        fflush(stdout); // Ensure the menu is printed before waiting for input
        scanf("%d", &i);
        while (getchar() != '\n')
            ; // flush leftover newline
        switch (i)
        {
        case 1:
            if (contact_init(&contact_list.contacts[contact_list.count]))
            {
                list_add_contact(&contact_list.contacts[contact_list.count], &contact_list);
            }
            else
            {
                printf("Failed to add contact due to validation errors.\n");
            }
            break;
        case 2:
            list_all_contacts(&contact_list);
            break;
        case 3:
            printf("Enter name to search: ");
            fgets(name, sizeof(name), stdin);         // Get search name from user input, using the name field of the first contact as a temporary buffer
            name[strcspn(name, "\n")] = '\0';         // Remove newline character
            list_search_contact(name, &contact_list); // Example search, replace "João" with user input for dynamic searching
            break;
        case 0:
            printf("Saindo...\n");
            return 0;
        default:
            printf("Opção inválida!\n");
            break;
        }
    }
}