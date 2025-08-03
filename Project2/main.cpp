/*
Author: Matthew Flores (matthewflores10@my.unt.edu)
Date: 07-19-2025
Instructor: Dr. Amar M. Maharjan
Description: Project 2 | Creates Contact List
*/
#include "mmf0192Project2_header.h"
#include <iostream>
using namespace std;

int main() {
    while (true) {
        // Show the menu options to the user
        displayMenu();

        // Ask the user to choose an operation (Add, Edit, etc.)
        Operation userChoice = askForChoice();

        int contactID;  // Will hold contact ID for Edit, Delete, Search

        // Perform the action based on user's choice
        switch (userChoice) {
            case ADD:
                // Add a new contact
                addContact();
                break;

            case EDIT:
                // Ask for contact ID and edit that contact
                contactID = askContactID(userChoice);
                editContact(contactID);
                break;

            case DELETE:
                // Ask for contact ID and delete that contact
                contactID = askContactID(userChoice);
                deleteContact(contactID);
                break;

            case SEARCH:
                // Ask for contact ID and display that contact
                contactID = askContactID(userChoice);
                searchContact(contactID);
                break;

            case DISPLAY:
                // Display all contacts in a table format
                display();
                break;

            case EXIT:
                // Exit the loop and terminate the program
                cout << "Goodbye!!!\n";
                return 0;

            default:
                break;
        }
    }

    return 0;
}

