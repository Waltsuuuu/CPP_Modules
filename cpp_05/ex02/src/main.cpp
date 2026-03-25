#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main() {
	std::cout << "\n--- SHRUBBERY FORM INFO PRINT TEST ---" << std::endl;
	try {
		ShrubberyCreationForm shrub("home");
		std::cout << shrub << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << "\n--- EXECUTE UNSIGNED FORM TEST ---" << std::endl;
	try {
		ShrubberyCreationForm shrub("unsigned_home");
		Bureaucrat bob("Bob", 1);

		bob.executeForm(shrub);
	}
	catch (std::exception &e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << "\n--- SIGNING GRADE TOO LOW TEST ---" << std::endl;
	try {
		RobotomyRequestForm robot("Bender");
		Bureaucrat bob("Bob", 150);

		bob.signAForm(robot);
	}
	catch (std::exception &e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << "\n--- EXECUTION GRADE TOO LOW TEST ---" << std::endl;
	try {
		RobotomyRequestForm robot("Marvin");
		Bureaucrat signer("Signer", 1);
		Bureaucrat executor("Executor", 100);

		signer.signAForm(robot);
		executor.executeForm(robot);
	}
	catch (std::exception &e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << "\n--- SUCCESSFUL SHRUBBERY EXECUTION TEST ---" << std::endl;
	try {
		ShrubberyCreationForm shrub("garden");
		Bureaucrat bob("Bob", 1);

		bob.signAForm(shrub);
		bob.executeForm(shrub);
		std::cout << shrub << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << "\n--- ROBOTOMY TEST (50% SUCCESS CHANCE) ---" << std::endl;
	try {
		RobotomyRequestForm robot("R2D2");
		Bureaucrat bob("Bob", 1);

		bob.signAForm(robot);
		bob.executeForm(robot);
	}
	catch (std::exception &e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << "\n--- PRESIDENTIAL PARDON TEST ---" << std::endl;
	try {
		PresidentialPardonForm pardon("Arthur Dent");
		Bureaucrat president("President", 1);

		president.signAForm(pardon);
		president.executeForm(pardon);
	}
	catch (std::exception &e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	return 0;
}