#include "Dog.hpp"
#include <iostream>

Dog::Dog() : Animal() {
	std::cout << "Dog constructed" << std::endl;
	_type = "Dog";
}

Dog::Dog(const Dog& copy) : Animal(copy) {
}

Dog& Dog::operator = (const Dog& other) {
	if (this != &other) {
		Animal::operator = (other);
	}
	return (*this);
}

Dog::~Dog() {
	std::cout << "Dog destructed" << std::endl;
}

void Dog::makeSound() const {
	std::cout << "Woof woof" << std::endl;
}