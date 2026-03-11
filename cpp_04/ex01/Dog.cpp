#include "Dog.hpp"
#include <iostream>

Dog::Dog() : Animal(), _brain(new Brain()){
	std::cout << "Dog constructed" << std::endl;
	_type = "Dog";
}

Dog::Dog(const Dog& copy) : Animal(copy), _brain(new Brain(*copy._brain)) {
	std::cout << "Dog copy constructed" << std::endl;
}

Dog& Dog::operator = (const Dog& other) {
	if (this != &other) {
		Animal::operator = (other);
		*_brain = *other._brain;
	}
	std::cout << "Dog assignment operator called" << std::endl;
	return (*this);
}

Dog::~Dog() {
	std::cout << "Dog destructed" << std::endl;
	delete _brain;
}

void Dog::makeSound() const {
	std::cout << "Woof woof" << std::endl;
}