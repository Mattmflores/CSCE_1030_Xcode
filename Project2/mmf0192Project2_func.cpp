#include "mmf0192Project2_header.h"
#include "getNumber.h"
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cstring>
using namespace std;

Contact* contacts = nullptr;
int numOfContacts = 0;

/*
Function:    loadContacts
Parameters:  int& numContacts – reference to store number of contacts loaded
Return:      Contact* – pointer to a dynamically allocated array of Contact structs
Description: Reads contact information from "contacts.dat", using getNumber()
             to determine how many contacts there are, allocates an array accordingly,
             fills each Contact from the file, and returns the pointer.
*/
Contact* loadContacts(int& numContacts) {
    // Get total entries and allocate once
    numContacts = getNumber();
    if (numContacts <= 0) {
        return nullptr;
    }
    // Allocate array for all contacts
    Contact* contactsArray = (Contact*)malloc(numContacts * sizeof(Contact));
    if (!contactsArray) {
        cerr << "Memory allocation failed" << endl;
        exit(1);
    }

    ifstream inFile("contacts.dat");
    if (!inFile.is_open()) {
        cerr << "File could not be opened" << endl;
        exit(1);
    }

    string line;
    int index = 0;
    while (getline(inFile, line) && index < numContacts) {
        if (line.empty()) continue;  // skip empty lines
        stringstream ss(line);
        string token;
        Contact& contact = contactsArray[index];

        // Parse ID
        getline(ss, token, ';');
        contact.contact_ID = stoi(token);
        // First name
        getline(ss, token, ';');
        contact.first_name = (char*)malloc(token.size() + 1);
        strcpy(contact.first_name, token.c_str());
        // Last name
        getline(ss, token, ';');
        contact.last_name = (char*)malloc(token.size() + 1);
        strcpy(contact.last_name, token.c_str());
        // Email
        getline(ss, token, ';');
        contact.email = (char*)malloc(token.size() + 1);
        strcpy(contact.email, token.c_str());
        // Phone
        getline(ss, token, ';');
        contact.phone = (char*)malloc(token.size() + 1);
        strcpy(contact.phone, token.c_str());
        // Address (rest of line)
        getline(ss, token);
        contact.address = (char*)malloc(token.size() + 1);
        strcpy(contact.address, token.c_str());

        ++index;
    }

    inFile.close();
    return contactsArray;
}

/*
Function:    findMaxid
Parameters:  Contact* allContacts – pointer to the array of contacts
             const int numContacts – number of contacts in the array
Return:      int – the highest (last) contact ID in the list
Description: Returns the contact_ID of the last contact in the list.
             If no contacts exist, prints an error message and returns 0.
*/
int findMaxid(Contact* allContacts, const int numContacts) {
    // Check if the contact list is null or has no entries
    if (allContacts == nullptr || numContacts == 0) {
        cerr << "No contacts found.\n";  // Show error message
        return 0;                        // Return 0 for empty list
    }

    // Return the contact_ID of the last contact
    return allContacts[numContacts - 1].contact_ID;
}

/*
Function:    addContactToDataFile
Parameters:  Contact* contacts – pointer to an array of Contact structures
             const int numContact – number of contacts in the array
Return:      void
Description: Writes all contact records to "contacts.dat", overwriting the file with the latest contact list.
*/
void addContactToDataFile(Contact* contacts, const int numContact) {
    ofstream outFile;
    outFile.open("contacts.dat");  // Open file for writing (overwrites if it exists)
    
    // Check if the file opened successfully
    if (!outFile.is_open()) {
        cerr << "File could not be opened";  // Print error message
        exit(1);  // Exit program if file can't be opened
    }

    // Loop through each contact and write their info to the file
    for (int i = 0; i < numContact; ++i) {
        Contact contact = contacts[i];  // Get the current contact
        outFile << contact.contact_ID << ";"       // Write contact ID
                << contact.first_name << ";"       // Write first name
                << contact.last_name << ";"        // Write last name
                << contact.email << ";"            // Write email
                << contact.phone << ";"            // Write phone number
                << contact.address << "\n";        // Write address and end line
    }
    
    outFile.close();  // Close the file
}

/*
Function:    displayMenu
Parameters:  None
Return:      void
Description: Displays the main menu options for the contact management system.
*/
void displayMenu() {
    printf("******Menu******\n");
    printf("1. Add\n");      // Option to add a new contact
    printf("2. Edit\n");     // Option to edit an existing contact
    printf("3. Delete\n");   // Option to delete a contact
    printf("4. Search\n");   // Option to search for a contact
    printf("5. Display\n");  // Option to display all contacts
    printf("6. Exit\n");     // Option to exit the program
    printf("****************\n");
}

/*
Function:    askContactID
Parameters:  Operation userChoice – the operation selected by the user (EDIT, DELETE, or SEARCH)
Return:      int – the contact ID entered by the user
Description: Prompts the user to enter the contact ID based on the selected operation type
             (edit, delete, or search) and returns the entered ID.
*/
int askContactID(Operation userChoice) {
    string userContactAction;
    int contactID;
    
    // Set the prompt message based on the user operation
    switch (userChoice) {
        case EDIT:
            userContactAction = "edit";
            break;
        case DELETE:
            userContactAction = "delete";
            break;
        case SEARCH:
            userContactAction = "search";
            break;
        default:
            break;
    }
    
    // Ask user to input the contact ID
    cout << "Enter contact id to " << userContactAction << ": ";
    scanf(" %d", &contactID);
    
    return contactID;
}

/*
Function:    clearBuffer
Parameters:  None
Return:      void
Description: Clears the input buffer by reading and discarding characters until a newline is found.
             This is useful to avoid leftover input affecting subsequent input operations.
*/
void clearBuffer() {
    while (getchar() != '\n');
}

/*
Function:    addContact
Parameters:  None
Return:      void
Description: Prompts the user to input new contact details (name, email, phone, etc.), generates a new contact ID,
             adds the contact to the existing dynamic array of contacts, writes the updated list to the file,
             and frees the dynamically allocated memory for the temporary contact.
*/
void addContact() {
    Contact* tempContact = (Contact*)malloc(sizeof(Contact));  // allocate memory for the new contact
    
    clearBuffer();  // clear any leftover input from previous scanf

    // Prompt and store first name
    printf("Enter first name: ");
    char inputFirstName[100];
    fgets(inputFirstName, sizeof(inputFirstName), stdin);
    if (strlen(inputFirstName) == 0) {
        cerr << "Name is empty\n";
        exit(1);
    }
    inputFirstName[strlen(inputFirstName) - 1] = '\0';  // remove newline
    tempContact->first_name = (char*)malloc(strlen(inputFirstName) + 1);
    strcpy(tempContact->first_name, inputFirstName);

    // Prompt and store last name
    cout << "Enter last name: ";
    char inputLastName[100];
    fgets(inputLastName, sizeof(inputLastName), stdin);
    inputLastName[strlen(inputLastName) - 1] = '\0';
    tempContact->last_name = (char*)malloc(strlen(inputLastName) + 1);
    strcpy(tempContact->last_name, inputLastName);

    // Prompt and store email
    cout << "Enter email: ";
    char inputEmail[100];
    fgets(inputEmail, sizeof(inputEmail), stdin);
    inputEmail[strlen(inputEmail) - 1] = '\0';
    tempContact->email = (char*)malloc(strlen(inputEmail) + 1);
    strcpy(tempContact->email, inputEmail);

    // Prompt and store phone number
    cout << "Enter phone: ";
    char inputPhone[100];
    fgets(inputPhone, sizeof(inputPhone), stdin);
    inputPhone[strlen(inputPhone) - 1] = '\0';
    tempContact->phone = (char*)malloc(strlen(inputPhone) + 1);
    strcpy(tempContact->phone, inputPhone);

    // Prompt and store address
    cout << "Enter address: ";
    char inputAddress[100];
    fgets(inputAddress, sizeof(inputAddress), stdin);
    inputAddress[strlen(inputAddress) - 1] = '\0';
    tempContact->address = (char*)malloc(strlen(inputAddress) + 1);
    strcpy(tempContact->address, inputAddress);

    // Load current contacts to get the latest ID
    int totalContacts = 0;
    Contact* existingContacts = loadContacts(totalContacts);
    tempContact->contact_ID = (totalContacts == 0) ? 1 : findMaxid(existingContacts, totalContacts) + 1;

    // Add new contact to the dynamic array
    Contact* expandedContacts = (Contact*)realloc(existingContacts, (totalContacts + 1) * sizeof(Contact));
    Contact& newSlot = expandedContacts[totalContacts];  // reference to the new slot

    // Copy all values into the newly allocated contact
    newSlot.contact_ID = tempContact->contact_ID;

    newSlot.first_name = (char*)malloc(strlen(tempContact->first_name) + 1);
    strcpy(newSlot.first_name, tempContact->first_name);

    newSlot.last_name = (char*)malloc(strlen(tempContact->last_name) + 1);
    strcpy(newSlot.last_name, tempContact->last_name);

    newSlot.email = (char*)malloc(strlen(tempContact->email) + 1);
    strcpy(newSlot.email, tempContact->email);

    newSlot.phone = (char*)malloc(strlen(tempContact->phone) + 1);
    strcpy(newSlot.phone, tempContact->phone);

    newSlot.address = (char*)malloc(strlen(tempContact->address) + 1);
    strcpy(newSlot.address, tempContact->address);

    // Update global pointer and count
    contacts = expandedContacts;
    numOfContacts = totalContacts + 1;

    // Write updated contact list to file
    addContactToDataFile(contacts, numOfContacts);

    // Clean up temporary contact memory
    free(tempContact->first_name);
    free(tempContact->last_name);
    free(tempContact->email);
    free(tempContact->phone);
    free(tempContact->address);
    free(tempContact);

    cout << "Added new contact successfully.\n";
}

/*
Function:    editContact
Parameters:  const int id – contact ID of the contact to edit
Return:      void
Description: Searches for a contact by ID, displays its current information,
             allows the user to update the contact's data, writes the updated
             list back to the file, and frees all dynamically allocated memory.
*/
void editContact(const int contactID) {
    int totalContacts = 0;
    Contact* contactList = loadContacts(totalContacts);

    int contactIndexToEdit = -1;
    for (int i = 0; i < totalContacts; ++i) {
        if (contactList[i].contact_ID == contactID) {
            contactIndexToEdit = i;
            break;
        }
    }

    // Handle case where contact is not found
    if (contactIndexToEdit == -1) {
        cout << "Contact ID " << contactID << " not found.\n";
        return;
    }

    // Reference the contact to edit
    Contact& contactToEdit = contactList[contactIndexToEdit];

    // Display current contact information
    printf("\nCurrent information of %s %s:\n", contactToEdit.first_name, contactToEdit.last_name);
    printf("==================================================================\n");
    printf("ID   Name                     Email                    Phone          Address\n");
    printf("==================================================================\n");
    printf("%-4d %-24s %-24s %-14s\n", contactToEdit.contact_ID, contactToEdit.first_name, contactToEdit.email, contactToEdit.phone);
    printf("%s\n", contactToEdit.address);
    printf("==================================================================\n");

    // Prepare for updates
    char inputBuffer[200];
    clearBuffer();  // clean leftover input

    // Update first name
    cout << "Update first name: ";
    fgets(inputBuffer, sizeof(inputBuffer), stdin);
    inputBuffer[strcspn(inputBuffer, "\n")] = '\0';
    free(contactToEdit.first_name);
    contactToEdit.first_name = (char*)malloc(strlen(inputBuffer) + 1);
    strcpy(contactToEdit.first_name, inputBuffer);

    // Update last name
    cout << "Update last name: ";
    fgets(inputBuffer, sizeof(inputBuffer), stdin);
    inputBuffer[strcspn(inputBuffer, "\n")] = '\0';
    free(contactToEdit.last_name);
    contactToEdit.last_name = (char*)malloc(strlen(inputBuffer) + 1);
    strcpy(contactToEdit.last_name, inputBuffer);

    // Update email
    cout << "Update email: ";
    fgets(inputBuffer, sizeof(inputBuffer), stdin);
    inputBuffer[strcspn(inputBuffer, "\n")] = '\0';
    free(contactToEdit.email);
    contactToEdit.email = (char*)malloc(strlen(inputBuffer) + 1);
    strcpy(contactToEdit.email, inputBuffer);

    // Update phone
    cout << "Update phone: ";
    fgets(inputBuffer, sizeof(inputBuffer), stdin);
    inputBuffer[strcspn(inputBuffer, "\n")] = '\0';
    free(contactToEdit.phone);
    contactToEdit.phone = (char*)malloc(strlen(inputBuffer) + 1);
    strcpy(contactToEdit.phone, inputBuffer);

    // Update address
    cout << "Update address: ";
    fgets(inputBuffer, sizeof(inputBuffer), stdin);
    inputBuffer[strcspn(inputBuffer, "\n")] = '\0';
    free(contactToEdit.address);
    contactToEdit.address = (char*)malloc(strlen(inputBuffer) + 1);
    strcpy(contactToEdit.address, inputBuffer);

    // Write updated contact list to file
    ofstream outFile("contacts.dat");
    if (!outFile.is_open()) {
        cerr << "Error opening contacts.dat for writing.\n";
        exit(1);
    }

    for (int i = 0; i < totalContacts; ++i) {
        Contact& currentContact = contactList[i];
        outFile << currentContact.contact_ID << ";"
                << currentContact.first_name << ";"
                << currentContact.last_name << ";"
                << currentContact.email << ";"
                << currentContact.phone << ";"
                << currentContact.address << "\n";
    }

    outFile.close();

    // Free memory used by all contacts
    for (int i = 0; i < totalContacts; ++i) {
        free(contactList[i].first_name);
        free(contactList[i].last_name);
        free(contactList[i].email);
        free(contactList[i].phone);
        free(contactList[i].address);
    }
    free(contactList);

    cout << "Updated existing contact successfully.\n";
}

/*
Function:    deleteContact
Parameters:  const int id – the contact ID to delete
Return:      void
Description: Deletes a contact by ID from the contact list and updates the file.
*/
void deleteContact(const int id) {
    int numContacts = 0;

    // Load all existing contacts into a dynamic array
    Contact* contactList = loadContacts(numContacts);

    // Find the index of the contact to delete
    int contactIndexToDelete = -1;
    for (int i = 0; i < numContacts; ++i) {
        if (contactList[i].contact_ID == id) {
            contactIndexToDelete = i;
            break;
        }
    }

    // If contact not found, print error and return
    if (contactIndexToDelete == -1) {
        cout << "Contact ID " << id << " not found.\n";
        return;
    }

    // Open file to overwrite with updated contact list
    ofstream outFile("contacts.dat");
    if (!outFile.is_open()) {
        cerr << "Error opening contacts.dat for writing.\n";
        exit(1);
    }

    // Write all contacts to file except the one being deleted
    for (int i = 0; i < numContacts; ++i) {
        if (i == contactIndexToDelete) continue;

        Contact& currentContact = contactList[i];
        outFile << currentContact.contact_ID << ";"
                << currentContact.first_name << ";"
                << currentContact.last_name << ";"
                << currentContact.email << ";"
                << currentContact.phone << ";"
                << currentContact.address << "\n";
    }

    outFile.close();

    // Free all dynamically allocated memory
    for (int i = 0; i < numContacts; ++i) {
        free(contactList[i].first_name);
        free(contactList[i].last_name);
        free(contactList[i].email);
        free(contactList[i].phone);
        free(contactList[i].address);
    }
    free(contactList);

    // Print success message
    cout << "Deleted existing contact successfully.\n";
}

/*
Function:    searchContact
Parameters:  const int id – the contact ID to search for
Return:      void
Description: Searches for a contact by ID and displays their information if found.
*/
void searchContact(const int id) {
    int numContacts = 0;

    // Load all existing contacts from the file
    Contact* contactList = loadContacts(numContacts);

    // Try to find the contact with the matching ID
    int contactIndexFound = -1;
    for (int i = 0; i < numContacts; ++i) {
        if (contactList[i].contact_ID == id) {
            contactIndexFound = i;
            break;
        }
    }

    // Print the table header
    cout << "====================================================================\n";
    cout << "ID   Name                  Email              Phone           Address\n";
    cout << "====================================================================\n";

    // If the contact was not found, show an error message
    if (contactIndexFound == -1) {
        cout << "Contact ID " << id << " not found.\n";
    } else {
        // If found, print the contact's information
        Contact& contact = contactList[contactIndexFound];
        cout << contact.contact_ID << "   "
             << contact.first_name << " " << contact.last_name << "     "
             << contact.email << "   "
             << contact.phone << "   "
             << contact.address << "\n";
    }

    cout << "====================================================================\n";

    // Free all memory used by the contact list
    for (int i = 0; i < numContacts; ++i) {
        free(contactList[i].first_name);
        free(contactList[i].last_name);
        free(contactList[i].email);
        free(contactList[i].phone);
        free(contactList[i].address);
    }
    free(contactList);
}

/*
Function:    display
Parameters:  None
Return:      void
Description: Loads all contacts from file and displays them in a formatted table.
*/
void display() {
    int numContacts = 0;

    // Load all contacts from the file into dynamic array
    Contact* contactList = loadContacts(numContacts);

    // Check if no contacts exist
    if (numContacts == 0) {
        cout << "No contacts to display.\n";
        return;
    }

    // Print table header
    cout << "============================================================================================\n";
    cout << left << setw(5) << "ID"
         << setw(25) << "Name"
         << setw(30) << "Email"
         << setw(15) << "Phone"
         << setw(45) << "Address" << "\n";
    cout << "============================================================================================\n";

    // Loop through each contact and display its details
    for (int i = 0; i < numContacts; ++i) {
        Contact& contact = contactList[i];
        string fullName = string(contact.first_name) + " " + string(contact.last_name);

        // Print contact ID, name, email, and phone on one line
        cout << left << setw(5) << contact.contact_ID
             << setw(25) << fullName
             << setw(30) << contact.email
             << setw(15) << contact.phone << "\n";

        // Print address indented on next line
        cout << setw(5) << " "  // Empty columns for alignment
             << setw(25) << " "
             << setw(30) << " "
             << setw(15) << " "
             << setw(45) << contact.address << "\n";

        // Print a row divider
        cout << "--------------------------------------------------------------------------------------------\n";
    }

    // Print table footer
    cout << "============================================================================================\n";

    // Free memory allocated for each contact
    for (int i = 0; i < numContacts; ++i) {
        free(contactList[i].first_name);
        free(contactList[i].last_name);
        free(contactList[i].email);
        free(contactList[i].phone);
        free(contactList[i].address);
    }

    // Free memory for contact list array
    free(contactList);
}

/*
Function:    askForChoice
Parameters:  None
Return:      Operation – the user’s selected menu option as an enum
Description: Prompts user to enter a valid menu choice. Repeats until a valid choice
             between 1 and 6 is entered. Converts the integer to the Operation enum.
*/
Operation askForChoice() {
    int userChoice;                   // Variable to hold user input number
    int inputResult = 0;              // Stores result of scanf to verify success
    const int inputSuccessCode = 1;   // Expected return from scanf on success
    bool isValidChoice = false;       // Flag to control input loop

    // Keep asking until a valid choice is entered
    while (!isValidChoice) {
        printf("Enter your choice: ");
        inputResult = scanf(" %d", &userChoice);

        // Check if input is a number and in valid menu range
        bool isInValidRange = userChoice >= 1 && userChoice <= 6;

        if (inputResult != inputSuccessCode || !isInValidRange) {
            while (getchar() != '\n'); // Clear the input buffer
            printf("Incorrect choice. Please enter again.\n");
            continue;
        } else {
            isValidChoice = true; // Exit loop
        }
    }

    // Cast the valid integer input to Operation enum and return it
    Operation selectedOperation = static_cast<Operation>(userChoice);
    return selectedOperation;
}
