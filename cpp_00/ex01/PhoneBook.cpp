#include "PhoneBook.hpp"
#include <iostream>
#include <string>

// Constructor
PhoneBook::PhoneBook() : _size(0), _nextIndex(0) {
    //  Size and nIndex are initialized using 'Initialization list',
    //  meaning the variable is created AND initalized to 0 immediately.
}

PhoneBook::~PhoneBook() {
    // Nothing to clean up.
    // Technically not needed, as the compiler would generate
    // an empty destructor automatically, but leaving it in for
    // learning purpose :)!
}

// Adds a contact to the contacts array
void PhoneBook::addContact(const Contact &contact) {
    _contacts[_nextIndex] = contact;

    if (_size < 8)
        _size++;

    _nextIndex = (_nextIndex + 1) % 8;  // Wraps to 0 at 8.
}

// Prints a phonebook field as 10 chars wide, with text right aligned.
// If text is longer than 10 chars, truncate and replace last char with '.'
static void printField(const std::string &str) {
    if (str.length() > 10) {
        std::cout << str.substr(0, 9) << ".";
    } else {
        std::cout << std::string(10 - str.length(), ' ') << str;
    }
}

// Displays a list of contacts (index, fName, lName, nName)
void    PhoneBook::displayAllContacts() const {
    if (_size == 0) {
        std::cout << "PhoneBook is empty." << std::endl;
        return ;
    }

    std::cout << "---------------------------------------------" << std::endl;
    std::cout << "     Index|First Name| Last Name|  Nickname" << std::endl;
    std::cout << "---------------------------------------------" << std::endl;

    // Loop over contact indexes and print them.
    for (int i = 0; i < _size; i++) {
        // Print index field
        std::cout <<std::string(10 - std::to_string(i).length(), ' ') << i << "|";

        // Print first-, last- and nickname fields.
        printField(_contacts[i].getFirstName());
        std::cout << "|";
        printField(_contacts[i].getLastName());
        std::cout << "|";
        printField(_contacts[i].getNickName());
        std::cout <<std::endl;
    }
}

// Displays a single contact - all information.
void    PhoneBook::displaySingleContact(int index) const {
    if (index < 0 || index >= _size) {
        std::cout << "Invalid contact index." << std::endl;
        return ;
    }

    const Contact &c = _contacts[index];

    std::cout << "First Name:     " << c.getFirstName()     << std::endl;
    std::cout << "Last Name:      " << c.getLastName()      << std::endl;
    std::cout << "Nickname:       " << c.getNickName()      << std::endl;
    std::cout << "Phone Number:   " << c.getPhoneNumber()   << std::endl;
    std::cout << "Darkest Secret: " << c.getDarkestSecret() << std::endl;
}