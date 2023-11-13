#include "Contact.h"
#include <cstring>
#include <iostream>

// Default constructor
Contact::Contact() {}

// Accessors
const char* Contact::getFirstName() const {
    return firstName;
}

const char* Contact::getFullName() const {
    return fullName;
}

const char* Contact::getLastName() const {
    return lastName;
}

const char* Contact::getPhone() const {
    return phone;
}

// Mutators
void Contact::setFirstName(const char* fName) {
    strncpy_s(firstName, sizeof(firstName), fName, _TRUNCATE);
}

void Contact::setFullName(const char* lName, const char* fName) {
    // Concatenate or separate last name, comma, space, and first name
    strcpy_s(fullName, sizeof(fullName), lName);
    strcat_s(fullName, sizeof(fullName), ", ");
    strcat_s(fullName, sizeof(fullName), fName);
}

void Contact::setLastName(const char* lName) {
    strncpy_s(lastName, sizeof(lastName), lName, _TRUNCATE);
}

void Contact::setPhone(const char* phoneNumber) {
    strncpy_s(phone, sizeof(phone), phoneNumber, _TRUNCATE);
}

// Display a single contact
void Contact::displayEntry() const {
    std::cout << "Last Name: " << getLastName() << std::endl;
    std::cout << "First Name: " << getFirstName() << std::endl;
    std::cout << "Phone: " << getPhone() << std::endl;
    std::cout << "Full Name: " << getFullName() << std::endl;
    std::cout << "--------------------------" << std::endl;
}
