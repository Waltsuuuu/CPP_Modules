#include "Dog.hpp"
#include <iostream>

Dog::Dog() : Animal() {
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

void Dog::makeSound() const {
	std::cout << "Woof woof" << std::endl;
}