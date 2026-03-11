#include "Cat.hpp"
#include <iostream>

Cat::Cat() : Animal(), _brain(new Brain()) {
	std::cout << "Cat constructed" << std::endl;
	_type = "Cat";
}

Cat::Cat(const Cat& copy) : Animal(copy), _brain(new Brain(*copy._brain)) {
	std::cout << "Cat copy constructed" << std::endl;
}

Cat& Cat::operator = (const Cat& other) {
	if (this != &other) {
		Animal::operator = (other);
		*_brain = *other._brain;
	}
	return (*this);
}

Cat::~Cat() {
	std::cout << "Cat destructed" << std::endl;
	delete _brain;
}

void Cat::makeSound() const {
	std::cout << "Meow" << std::endl;
}