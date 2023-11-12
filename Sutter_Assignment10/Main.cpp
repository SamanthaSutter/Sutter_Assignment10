// Main.cpp
#include <iostream>
#include <fstream>
#include "Contact.h"

// Function prototypes
void readFromFile(Contact[]);
void searchContacts(Contact[], const char[]);
void displayEntry(Contact);

int main() {
    Contact contacts[10];

    // Read data from the file and populate the contacts array
    readFromFile(contacts);

    // Prompt user to enter the search last name
    char searchLastName[40];
    std::cout << "Enter last name to search: ";
    std::cin.getline(searchLastName, sizeof(searchLastName));

    // Search and display matching contacts
    searchContacts(contacts, searchLastName);

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
        inputFile.getline(contacts[i].getLastName(), sizeof(contacts[i].getLastName()));
        inputFile.getline(contacts[i].getFirstName(), sizeof(contacts[i].getFirstName()));
        inputFile.getline(contacts[i].getPhone(), sizeof(contacts[i].getPhone()));

        // Set full name
        contacts[i].setFullName(contacts[i].getLastName(), contacts[i].getFirstName());
    }

    inputFile.close();
}

// Function to search contacts by last name and display matching entries
void searchContacts(Contact contacts[], const char searchLastName[]) {
    for (int i = 0; i < 10; ++i) {
        if (strcmp(contacts[i].getLastName(), searchLastName) == 0) {
            displayEntry(contacts[i]);
        }
    }
}

// Function to display a single contact entry
void displayEntry(Contact contact) {
    std::cout << "Last Name: " << contact.getLastName() << std::endl;
    std::cout << "First Name: " << contact.getFirstName() << std::endl;
    std::cout << "Phone: " << contact.getPhone() << std::endl;
    std::cout << "Full Name: " << contact.getFullName() << std::endl;
    std::cout << "--------------------------" << std::endl;
}
