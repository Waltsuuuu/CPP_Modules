#include "Bureaucrat.hpp"
#include <iostream>

int main() {
	try {
		Bureaucrat waldo2("Waldo2", 150);
		std::cout << waldo2 << std::endl;
		waldo2.incrementGrade();
	}
	catch (const std::exception& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	return 0;
}