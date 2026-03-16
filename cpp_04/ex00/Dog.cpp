#include "Dog.hpp"
#include <iostream>

Dog::Dog() : Animal() {
	std::cout << "Dog constructed" << std::endl;
	_type = "Dog";
}

Dog::Dog(const Dog& copy) : Animal(copy) {
	std::cout << "Dog copy constructed" << std::endl;
}

Dog& Dog::operator = (const Dog& other) {
	if (this != &other) {
		Animal::operator = (other);
	}
	std::cout << "Dog copy assignment called" << std::endl;
	return (*this);
}

Dog::~Dog() {
	std::cout << "Dog destructed" << std::endl;
}

void Dog::makeSound() const {
	std::cout << "Woof woof" << std::endl;
}