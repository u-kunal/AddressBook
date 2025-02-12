#include <stdio.h>
#include "Contact.h"
#include "Menu.h"

int main()
{
    Contact contacts[MAX_CONTACTS];
    int contactCount = 0;

    // Load dummy contacts
    loadDummyContacts(contacts, &contactCount);

    int choice;
    do
    {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addContact(contacts, &contactCount);
            break;
        case 2:
            listContacts(contacts, contactCount);
            break;
        case 3:
            editContact(contacts, contactCount);
            break;
        case 4:
            deleteContact(contacts, &contactCount);
            break;
        case 5:
            searchContact(contacts, contactCount);
            break;
        case 6:
            saveContacts(contacts, contactCount);
            break;
        case 7:
            printf("Exiting the program. Goodbye!\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
            break;
        }
    } while (choice != 7);

    return 0;
}