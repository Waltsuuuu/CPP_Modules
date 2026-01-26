#include "Harl.hpp"
#include <string>
#include <iostream>

int main(int argc, char *argv[]) {
	Harl myHarl;

	if (argc != 2) {
		std::cout << "Use ./harlFilter <level>\n";
		return (1);
	}

	std::string levels[] = { 
		"DEBUG", 
		"INFO", 
		"WARNING", 
		"ERROR" 
	};

	std::string input = argv[1];
	int index = 5;
	for (int i = 0; i < 4; i++) {
		if (levels[i] == input) {
			index = i + 1;
		}
	}

	switch (index) {
		case 1:
			std::cout << "[ DEBUG ]\n";
			myHarl.complain("DEBUG");
		case 2:
			std::cout << "[ INFO ]\n";
			myHarl.complain("INFO");
		case 3:
			std::cout << "[ WARNING ]\n";
			myHarl.complain("WARNING");
		case 4:
			std::cout << "[ ERROR ]\n";
			myHarl.complain("ERROR");
			break ;
		case 5:
			std::cout << "[ Probably complaining about insignificant problems ]\n";
	}
	
	return (0);
}