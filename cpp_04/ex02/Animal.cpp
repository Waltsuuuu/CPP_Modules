#include "Animal.hpp"
#include <iostream>

Animal::Animal() : _type("Animal") {
	std::cout << "Animal constructed" << std::endl;
}

Animal::Animal(const Animal& copy) : _type(copy._type) {
	std::cout << "Animal copy constructed" << std::endl;
}

Animal& Animal::operator = (const Animal& other) {
	if (this != &other) {
		this->_type = other._type;
	}
	return (*this);
}

Animal::~Animal() {
	std::cout << "Animal destructed" << std::endl;
}

void Animal::makeSound() const {
	std::cout << "Animal noises..." << std::endl;
}

std::string Animal::getType() const {
	return (_type);
}