
#include "Contact.h"
#include <cstring>

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
    strncpy(firstName, fName, sizeof(firstName) - 1);
    firstName[sizeof(firstName) - 1] = '\0';
}

void Contact::setFullName(const char* lName, const char* fName) {
    // Concatenate or seperate last name, comma, space, and first name
    strcpy(fullName, lName);
    strcat(fullName, ", ");
    strcat(fullName, fName);
    fullName[sizeof(fullName) - 1] = '\0'; 

void Contact::setLastName(const char* lName) {
    strncpy(lastName, lName, sizeof(lastName) - 1);
    lastName[sizeof(lastName) - 1] = '\0';
}

void Contact::setPhone(const char* phoneNumber) {
    strncpy(phone, phoneNumber, sizeof(phone) - 1);
    phone[sizeof(phone) - 1] = '\0';
}
