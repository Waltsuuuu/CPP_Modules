#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main() {
	try {
		ShrubberyCreationForm ShrubForm("home");
		Bureaucrat Bob("Bob", 75);
	
		Bob.signAForm(ShrubForm);
		ShrubForm.execute(Bob);
	}
	catch (std::exception& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << std::endl;

	try {
		RobotomyRequestForm RoboForm("WAZAAAA");
		Bureaucrat Bob("Bob", 1);
	
		Bob.signAForm(RoboForm);
		RoboForm.execute(Bob);
	}
	catch (std::exception& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << std::endl;

	try {
		PresidentialPardonForm PresForm("WAZAAAA");
		Bureaucrat Bob("Bob", 5);
	
		Bob.signAForm(PresForm);
		PresForm.execute(Bob);
	}
	catch (std::exception& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
}