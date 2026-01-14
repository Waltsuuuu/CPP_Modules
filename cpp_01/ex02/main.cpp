#include <string>
#include <iostream>

int main() {
	// Variable
	std::string brain = "HI THIS IS BRAIN";	
	
	// Pointer
	std::string* stringPTR = &brain;
	
	// Reference (Must be initialized and cannot be chaned to refer to something else later)
	std::string& stringREF = brain;

	std::cout << "Memory address of the string variable: " << &brain << "\n";
	std::cout << "Memory address held by stringPTR: " << stringPTR << "\n";
	std::cout << "Memory address held by stringREF: " << &stringREF <<"\n";

	std::cout << "The value of the string variable: " << brain << "\n";
	std::cout << "The value pointed to by stringPTR: " << *stringPTR << "\n";
	std::cout << "The value pointed to by stringREF: " << stringREF << "\n";
 
}