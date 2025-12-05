#include <iostream>
#include <string>
#include "PhoneBook.hpp"
#include "Contact.hpp"

static std::string promptInput(const std::string &fieldName) {
    std::string input;

    while (true) {
        std::cout << fieldName << ": ";
        if (!std::getline(std::cin, input)) {
            std::cout << "\n Input error. Goodbye!" << std::endl;
            std::exit(1);
        }
        if (!input.empty())
            return input;
        std::cout << "Field cannot be empty. Try again." << std::endl;   
    }
}

int main() {
    PhoneBook phoneBook;
    std::string command;

    while (true) {
        std::cout << "Enter command (ADD, SEARCH, EXIT): ";
        if (!std::getline(std::cin, command)) {
            std::cout << "\nGoodbye!" << std::endl;
            break ;
        }

        if (command == "ADD") {
            Contact contact;

            std::cout << std::endl;
            std::string firstName     = promptInput("First name");
            std::string lastName      = promptInput("Last name");
            std::string nickName      = promptInput("Nickname");
            std::string phoneNumber   = promptInput("Phone number");
            std::string darkestSecret = promptInput("Darkest secret");
            std::cout << std::endl;

            contact.setFirstName(firstName);
            contact.setLastName(lastName);
            contact.setNickName(nickName);
            contact.setPhoneNumber(phoneNumber);
            contact.setDarkestSecret(darkestSecret);

            phoneBook.addContact(contact);
            std::cout << firstName << " added to contacts!" << std::endl << std::endl;
        }
        else if (command == "SEARCH") {
            if (phoneBook.displayAllContacts() == 0)
                continue ;

            std::cout << "Enter index to view details: ";
            std::string indexStr;
            if (!std::getline(std::cin, indexStr)) {
                std::cout << "\nInput error. Goodbye!" << std::endl;
                break ;
            }
        
            // Validate input
            bool validNumber = true;
            for (std::size_t i = 0; i < indexStr.length(); i++) {
                if (!std::isdigit(indexStr[i])) {
                    validNumber = false;
                    break ;
                }
            }

            if (!validNumber || indexStr.empty()) {
                std::cout << "Invalid index input." << std::endl;
                continue ;
            }

            int index = std::atoi(indexStr.c_str());
            phoneBook.displaySingleContact(index);
        }
        else if (command == "EXIT") {
            std::cout << std::endl;
            std::cout << "Goodbye!" << std::endl;
            break ;
        }
        else if (!command.empty()) {
            std::cout << std::endl;
            std::cout << "Unknown command. Use ADD, SEARCH, or EXIT." << std::endl;
            std::cout << std::endl;
        }
    }
    return 0;
}