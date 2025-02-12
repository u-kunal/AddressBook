#include <stdio.h>
#include <string.h>
#include "Contact.h"

void addContact(Contact contacts[], int *count)
{
    if (*count >= MAX_CONTACTS)
    {
        printf("Contact list is full. Cannot add more contacts.\n");
        return;
    }

    printf("Enter name: ");
    scanf(" %[^\n]s", contacts[*count].name);

    printf("Enter phone: ");
    scanf(" %[^\n]s", contacts[*count].phone);

    printf("Enter email: ");
    scanf(" %[^\n]s", contacts[*count].email);

    (*count)++;
    printf("Contact added successfully!\n");
}

void listContacts(Contact contacts[], int count)
{
    if (count == 0)
    {
        printf("No contacts available.\n");
        return;
    }

    printf("\nList of Contacts:\n");
    for (int i = 0; i < count; i++)
    {
        printf("%d. Name: %s, Phone: %s, Email: %s\n", i + 1, contacts[i].name, contacts[i].phone, contacts[i].email);
    }
}

void editContact(Contact contacts[], int count)
{
    char name[50];
    printf("Enter the name of the contact to edit: ");
    scanf(" %[^\n]s", name);

    int found = 0;
    for (int i = 0; i < count; i++)
    {
        if (strcmp(contacts[i].name, name) == 0)
        {
            printf("Enter new phone number: ");
            scanf(" %[^\n]s", contacts[i].phone);
            printf("Enter new email: ");
            scanf(" %[^\n]s", contacts[i].email);
            printf("Contact edited successfully!\n");
            found = 1;
            break;
        }
    }
    if (!found)
    {
        printf("Contact not found.\n");
    }
}

void deleteContact(Contact contacts[], int *count)
{
    char name[50];
    printf("Enter the name of the contact to delete: ");
    scanf(" %[^\n]s", name);

    int found = 0;
    for (int i = 0; i < *count; i++)
    {
        if (strcmp(contacts[i].name, name) == 0)
        {
            found = 1;
            for (int j = i; j < *count - 1; j++)
            {
                contacts[j] = contacts[j + 1]; // Shift contacts left
            }
            (*count)--;
            printf("Contact deleted successfully!\n");
            break;
        }
    }
    if (!found)
    {
        printf("Contact not found.\n");
    }
}

void searchContact(Contact contacts[], int count)
{
    char name[50];
    printf("Enter the name of the contact to search: ");
    scanf(" %[^\n]s", name);

    int found = 0;
    for (int i = 0; i < count; i++)
    {
        if (strcmp(contacts[i].name, name) == 0)
        {
            printf("Contact found: Name: %s, Phone: %s, Email: %s\n", contacts[i].name, contacts[i].phone, contacts[i].email);
            found = 1;
            break;
        }
    }
    if (!found)
    {
        printf("Contact not found.\n");
    }
}

void saveContacts(Contact contacts[], int count)
{
    FILE *file = fopen("contacts.txt", "w");
    if (file == NULL)
    {
        printf("Error opening file for saving contacts.\n");
        return;
    }

    for (int i = 0; i < count; i++)
    {
        fprintf(file, "Name: %s\nPhone: %s\nEmail: %s\n\n", contacts[i].name, contacts[i].phone, contacts[i].email);
    }
    fclose(file);
    printf("Contacts saved to 'contacts.txt' successfully!\n");
}

void loadDummyContacts(Contact contacts[], int *count)
{
    const char *names[] = {"Sudhanshu", "Chinmaya", "Rakesh", "Debashish", "Pintu", "Aditya", "Biswaranjan", "Bimal", "Subham", "Chandan", "Jayant", "Soumya", "Vinod", "Sourav", "Ashish"};
    const char *phones[] = {"+919876543210", "+919876543211", "+919876543212", "+919876543213", "+919876543214", "+919876543215", "+919876543216", "+919876543217", "+919876543218", "+919876543219", "+919876543220", "+919876543221", "+919856743210", "+917766589320", "+91966854321"};
    const char *emails[] = {"sudhanshu@example.com", "chinmaya@example.com", "rakesh@example.com", "debashish@example.com", "pintu@example.com", "aditya@example.com", "biswaranjan@example.com", "bimal@example.com", "subham@example.com", "chandan@example.com", "jayant@example.com", "soumya@example.com", "vinod@example.com", "sourav@example.com", "ashish@example.com"};

    for (int i = 0; i < 15; i++)
    {
        strcpy(contacts[*count].name, names[i]);
        strcpy(contacts[*count].phone, phones[i]);
        strcpy(contacts[*count].email, emails[i]);
        (*count)++;
    }
}