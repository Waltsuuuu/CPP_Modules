#include "Bureaucrat.hpp"
#include <iostream>

int main() {
	try {
		Bureaucrat waldo("Waldo", 0);
		Bureaucrat waldo2("Waldo2", 151);
	}
	catch (const std::exception& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	return 0;
}