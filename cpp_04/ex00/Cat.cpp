#include "Cat.hpp"
#include <iostream>

Cat::Cat() : Animal() {
	std::cout << "Cat constructed" << std::endl;
	_type = "Cat";
}

Cat::Cat(const Cat& copy) : Animal(copy) {
	std::cout << "Cat copy constructed" << std::endl;
}

Cat& Cat::operator = (const Cat& other) {
	if (this != &other) {
		Animal::operator = (other);
	}
	std::cout << "Cat copy assignment called" << std::endl;
	return (*this);
}

Cat::~Cat() {
	std::cout << "Cat destructed" << std::endl;
}

void Cat::makeSound() const {
	std::cout << "Meow" << std::endl;
}