#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main() {
	std::cout << "--- FORM INFO PRINT TEST ---" << std::endl;
	try {
		Form Contract("Contract", 75, 20);
		std::cout << Contract << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << "--- GRADE TOO LOW TEST ---" << std::endl;
	std::cout << "Attempting to instantiate Form with grade > 150..." << std::endl;
	try {
		Form Contract("Contract", 151, 1);
	}
	catch (std::exception &e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << "\n--- GRADE TOO HIGH TEST ---" << std::endl;
	std::cout << "Attempting to instantiate Form with grade < 1..." << std::endl;	
	try {
		Form Contract("Contract", 0, 1);
	}
	catch (std::exception &e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << "\n--- SIGNING GRADE TOO LOW TEST ---" << std::endl;
	std::cout << "Attempting to sign form with too low grade..." << std::endl;
	try {
		Form Contract("Contract", 10, 10);
		Bureaucrat Bob("Bob", 20);
		
		Bob.signForm(Contract);
	}
	catch (std::exception &e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << "\n--- SUCCESSFUL SIGNING TEST + PRINT ---" << std::endl;
	try {
		
		Form Contract("Contract", 10, 10);
		Bureaucrat Bob("Bob", 10);
		
		Contract.beSigned(Bob);

		std::cout << std::endl;
		std::cout << Contract << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	return 0;
}