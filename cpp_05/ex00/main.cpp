#include "Bureaucrat.hpp"
#include <iostream>

int main() {
	try {
		std::cout << "--- GRADE TOO LOW TEST ---" << std::endl;
		std::cout << "Instantiating Bureaucrat with grade > 150" << std::endl;
		Bureaucrat waldo("Waldo", 151);
	}
	catch (const std::exception& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	try {
		std::cout << "\n--- GRADE TOO HIGH TEST ---" << std::endl;
		std::cout << "Instantiating Bureaucrat with grade < 1" << std::endl;
		Bureaucrat waldo("Waldo", 0);
	}
	catch (const std::exception& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	try {
		std::cout << "\n--- INCREMENTING TOO LOW ---" << std::endl;
		std::cout << "Instantiating Bureaucrat with grade 150" << std::endl;
		Bureaucrat waldo("Waldo", 150);
		std::cout << waldo << std::endl;
		waldo.decrementGrade();
	}
	catch (const std::exception& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	return 0;
}