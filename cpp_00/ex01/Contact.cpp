#include "Contact.hpp"

// The 'Contact::' prefix tells the compiler that this function is the
// implementation of the method declared in the 'Contact' class.

// Without the Contact:: prefix, the function becomes a normal
// standalone function, not a class member, and therefore it cannot 
// access private variables like _firstName;

// Constructor
Contact::Contact() {
    // Does nothing.
    // std::string's initialize to empty strings by default.
}

// Destructor
Contact::~Contact() {
    // Nothing to clean up.
    // std::string's handle their own memory.
}

// Setters
void    Contact::setFirstName(const std::string &firstName) {
    _firstName = firstName;
}

void    Contact::setLastName(const std::string &lastName) {
    _lastName = lastName;
}

void    Contact::setNickName(const std::string &nickName) {
    _nickName = nickName;
}

void    Contact::setPhoneNumber(const std::string &phoneNumber) {
    _phoneNumber = phoneNumber;
}

void    Contact::setDarkestSecret(const std::string &darkestSecret) {
    _darkestSecret = darkestSecret;
}

// Getters
std::string Contact::getFirstName() const {
    return _firstName;
}

std::string Contact::getLastName() const {
    return _lastName;
}

std::string Contact::getNickName() const {
    return _nickName;
}

std::string Contact::getPhoneNumber() const {
    return _phoneNumber;
}

std::string Contact::getDarkestSecret() const {
    return _darkestSecret;
}

