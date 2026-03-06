#include "Cat.hpp"
#include <iostream>

Cat::Cat() : Animal() {
	_type = "Cat";
}

Cat::Cat(const Cat& copy) : Animal(copy) {
}

Cat& Cat::operator = (const Cat& other) {
	if (this != &other) {
		Animal::operator = (other);
	}
	return (*this);
}

void Cat::makeSound() const {
	std::cout << "Meow" << std::endl;
}