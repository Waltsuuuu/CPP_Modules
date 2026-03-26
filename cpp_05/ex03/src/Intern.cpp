#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

Intern::Intern() {
}

Intern::~Intern() {
}

const char* Intern::InvalidFormException::what() const noexcept {
	return ("Invalid form name.\nValid names: shrubbery creation, robotomy request, presidential pardon.");
}

// --- Member Functions ---

AForm* Intern::makeForm(std::string formName, std::string target) {
	std::string validForms[3] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};

	AForm* form = nullptr;

	for (int i = 0; i < 3; i++) {
		if (formName == validForms[i]) {
			switch (i) {
				case 0:
					form = new ShrubberyCreationForm(target);
					break ;
				case 1: 
					form = new RobotomyRequestForm(target);
					break ;
				case 2:
					form = new PresidentialPardonForm(target);
					break ;
				}
			std::cout << "Intern creates " << formName << std::endl;
			return (form);
		}
	}

	throw InvalidFormException();
}