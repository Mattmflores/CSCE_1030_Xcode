#include <string>
using namespace std;

#ifndef MMF0192PROJECT2_HEADER_H
#define MMF0192PROJECT2_HEADER_H

void displayMenu();
void validateChoice(const int* userChoice);

enum Operation {
    ADD = 1,
    EDIT = 2,
    DELETE = 3,
    SEARCH = 4,
    DISPLAY = 5,
    EXIT = 6
};

Operation askForChoice();

typedef struct {
    int contact_ID;
    char* phone;
    char* first_name;
    char* last_name;
    char* email;
    char* address;
} Contact;

int getNumber();

void addContact();

void editContact(const int id);

void deleteContact(const int id);

void searchContact(const int id);

void display ();

Contact* loadContacts(int &numContacts);

int findMaxId(Contact *allContacts, const int numContacts);

int askContactID(Operation userChoice);

#endif
