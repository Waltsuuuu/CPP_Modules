#include "Base.hpp"
#include "Aclass.hpp"
#include "Bclass.hpp"
#include "Cclass.hpp"
#include <cstdlib>
#include <iostream>

Base* generate(void) {
	int random = rand() % 3;

	if (random == 0) {
		std::cout << "Generated A class" << std::endl;
		return new Aclass;
	}
	if (random == 1) {
		std::cout << "Generated B class" << std::endl;
		return new Bclass;
	}
	std::cout << "Generated C class" << std::endl; 
	return new Cclass;
}