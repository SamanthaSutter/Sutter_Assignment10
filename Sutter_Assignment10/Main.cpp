/* Samantha Sutter
*  ITDEV-185
*  Assignment 10
*/

#include <iostream>
#include <fstream>
#include "Contact.h"

// Function prototypes
void readFromFile(Contact[]);
void searchContacts(Contact[], const char[]);
void displayAllContacts(Contact[]);
void addContact(Contact[], int&);

int main() {
    Contact contacts[10];
    int contactCount = 0;

    // Read data from the file & populate the contacts array
    readFromFile(contacts);

    int choice;
    do {
        // Display menu to user
        std::cout << "\n===== Contact Menu =====" << std::endl;
        std::cout << "1. Find a contact" << std::endl;
        std::cout << "2. Add a contact" << std::endl;
        std::cout << "3. Display all contacts" << std::endl;
        std::cout << "4. Exit" << std::endl;
        std::cout << "=========================" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1: {
            // Find contact
            char searchLastName[40];
            std::cout << "Enter last name to search: ";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Clear input buffer
            std::cin.getline(searchLastName, sizeof(searchLastName));
            searchContacts(contacts, searchLastName);
            break;
        }
        case 2: {
            // Add a contact
            addContact(contacts, contactCount);
            break;
        }
        case 3: {
            // Display all contacts
            displayAllContacts(contacts);
            break;
        }
        case 4:
            std::cout << "Exiting the program. Goodbye!\n";
            break;
        default:
            std::cout << "Invalid choice. Please enter a valid option.\n";
        }
    } while (choice != 4);

    return 0;
}

// Function to read data from file and populate the array of Contact objects
void readFromFile(Contact contacts[]) {
    std::ifstream inputFile("contacts.txt");
    if (!inputFile.is_open()) {
        std::cerr << "Error opening file!" << std::endl;
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < 10; ++i) {
        inputFile.getline(const_cast<char*>(contacts[i].getLastName()), 20);
        inputFile.getline(const_cast<char*>(contacts[i].getFirstName()), 20);
        inputFile.getline(const_cast<char*>(contacts[i].getPhone()), 14);
        inputFile.ignore(); 

        // Set full name
        contacts[i].setFullName(contacts[i].getLastName(), contacts[i].getFirstName());
    }

    inputFile.close();
}

// Function to search contacts by last name and display matching entries
void searchContacts(Contact contacts[], const char searchLastName[]) {
    bool found = false;
    for (int i = 0; i < 10; ++i) {
        if (strcmp(contacts[i].getLastName(), searchLastName) == 0) {
            contacts[i].displayEntry(); // Display the contact entry
            found = true;
        }
    }

    if (!found) {
        std::cout << "No matching contacts found.\n";
    }
}

// Display all contact entries
void displayAllContacts(Contact contacts[]) {
    for (int i = 0; i < 10; ++i) {
        contacts[i].displayEntry(); // Display the contact entry
    }
}

// Add a new contact
void addContact(Contact contacts[], int& contactCount) {
    if (contactCount < 10) {
        std::cout << "Enter last name: ";
        std::cin.getline(const_cast<char*>(contacts[contactCount].getLastName()), 20);
        std::cout << "Enter first name: ";
        std::cin.getline(const_cast<char*>(contacts[contactCount].getFirstName()), 20);
        std::cout << "Enter phone number: ";
        std::cin.getline(const_cast<char*>(contacts[contactCount].getPhone()), 14);

        // Set full name
        contacts[contactCount].setFullName(contacts[contactCount].getLastName(), contacts[contactCount].getFirstName());

        std::cout << "Contact added successfully.\n";
        contactCount++;
    }
    else {
        std::cout << "Contact list is full. Cannot add more contacts.\n";
    }
}

