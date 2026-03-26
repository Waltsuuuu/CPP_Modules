#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <iostream>

int main() {
	std::cout << "\n--- INTERN CREATES SHRUBBERY FORM TEST ---" << std::endl;
	try {
		Intern someRandomIntern;
		AForm* form = someRandomIntern.makeForm("shrubbery creation", "home");

		std::cout << *form << std::endl;
		delete form;
	}
	catch (std::exception &e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << "\n--- INTERN CREATES ROBOTOMY FORM TEST ---" << std::endl;
	try {
		Intern someRandomIntern;
		AForm* form = someRandomIntern.makeForm("robotomy request", "Bender");

		std::cout << *form << std::endl;
		delete form;
	}
	catch (std::exception &e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << "\n--- INTERN CREATES PRESIDENTIAL FORM TEST ---" << std::endl;
	try {
		Intern someRandomIntern;
		AForm* form = someRandomIntern.makeForm("presidential pardon", "Arthur Dent");

		std::cout << *form << std::endl;
		delete form;
	}
	catch (std::exception &e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << "\n--- INTERN INVALID FORM TEST ---" << std::endl;
	try {
		Intern someRandomIntern;
		AForm* form = someRandomIntern.makeForm("coffee request", "Nobody");

		std::cout << *form << std::endl;
		delete form;
	}
	catch (std::exception &e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << "\n--- INTERN FORM + SIGN + EXECUTE TEST ---" << std::endl;
	try {
		Intern someRandomIntern;
		Bureaucrat bob("Bob", 1);
		AForm* form = someRandomIntern.makeForm("robotomy request", "Marvin");

		bob.signAForm(*form);
		bob.executeForm(*form);
		delete form;
	}
	catch (std::exception &e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	return 0;
}