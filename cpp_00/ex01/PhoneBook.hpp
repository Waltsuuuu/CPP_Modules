#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {
    private:
        Contact _contacts[8];   // Array of contacts (max 8)
        int     _size;          // Current number of contacts
        int     _nextIndex;     // Which index to insert the next contact

    public:
        // Constructor and deconstructor
        PhoneBook();
        ~PhoneBook();

        // Adds a contact to the array
        void    addContact(const Contact &contact);

        // Show list of contacts (index, fName, lName, nName)
        void    displayContacts() const;

        // Show full info of a single contact
        void    displayContact(int index) const;
}

#endif