// Contact.h
#ifndef CONTACT_H
#define CONTACT_H

class Contact {
private:
    char firstName[20];
    char fullName[40];
    char lastName[20];
    char phone[14];

public:
    // Default constructor
    Contact();

    // Accessors
    const char* getFirstName() const;
    const char* getFullName() const;
    const char* getLastName() const;
    const char* getPhone() const;

    // Mutators
    void setFirstName(const char* fName);
    void setFullName(const char* lName, const char* fName);
    void setLastName(const char* lName);
    void setPhone(const char* phoneNumber);
};

#endif  
