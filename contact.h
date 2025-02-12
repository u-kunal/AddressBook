#ifndef CONTACT_H
#define CONTACT_H

#define MAX_CONTACTS 100

// Define a structure for storing contact information
typedef struct
{
    char name[50];
    char phone[15];
    char email[50];
} Contact;

// Function prototypes for managing contacts
void addContact(Contact contacts[], int *count);
void listContacts(Contact contacts[], int count);
void editContact(Contact contacts[], int count);
void deleteContact(Contact contacts[], int *count);
void searchContact(Contact contacts[], int count);
void saveContacts(Contact contacts[], int count);
void loadDummyContacts(Contact contacts[], int *count);

#endif