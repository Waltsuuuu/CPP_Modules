#include "Cat.hpp"
#include <iostream>

Cat::Cat() : Animal() {
	_type = "Cat";
}

void Cat::makeSound() const {
	std::cout << "Meow" << std::endl;
}