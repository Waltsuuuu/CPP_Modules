#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

int main() {
	try {
		ShrubberyCreationForm ShrubForm("home");
		Bureaucrat Bob("Bob", 1);
	
		Bob.signAForm(ShrubForm);
		ShrubForm.execute(Bob);
	}
	catch (std::exception& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
}