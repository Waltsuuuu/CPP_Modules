#include "Bureaucrat.hpp"
#include <iostream>

int main() {
	try {
		std::cout << "--- GRADE TOO LOW TEST ---" << std::endl;
		std::cout << "Attempting to instantiate Bureaucrat with grade > 150..." << std::endl;
		Bureaucrat waldo("Waldo", 151);
	}
	catch (const std::exception& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	try {
		std::cout << "\n--- GRADE TOO HIGH TEST ---" << std::endl;
		std::cout << "Attempting to instantiate Bureaucrat with grade < 1..." << std::endl;
		Bureaucrat waldo("Waldo", 0);
	}
	catch (const std::exception& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	try {
		std::cout << "\n--- DECREMENTING TOO LOW ---" << std::endl;
		std::cout << "Instantiating Bureaucrat with grade 150 and attempting to decrement grade..." << std::endl;
		Bureaucrat waldo("Waldo", 150);
		std::cout << waldo << std::endl;
		waldo.decrementGrade();
	}
	catch (const Bureaucrat::GradeTooLowException& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	try {
		std::cout << "\n--- INCREMENTING TOO HIGH ---" << std::endl;
		std::cout << "Instantiating Bureaucrat with grade 1 and attempting to increment grade..." << std::endl;
		Bureaucrat waldo("Waldo", 1);
		std::cout << waldo << std::endl;
		waldo.incrementGrade();
	}
	catch (const Bureaucrat::GradeTooHighException& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	try {
		std::cout << "\n--- VALID BUREAUCRAT ---" << std::endl;
		std::cout << "Instantiating Bureaucrat with grade 75 and incrementing / decrementing grade..." << std::endl;
		Bureaucrat waldo("Waldo", 75);
		std::cout << waldo << std::endl;
		waldo.incrementGrade();
		std::cout << waldo << std::endl;
		waldo.decrementGrade();
		std::cout << waldo << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	return 0;
}