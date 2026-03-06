#include "Animal.hpp"
#include <iostream>

Animal::Animal() : _type("Animal") {
}

Animal::Animal(const Animal& copy) : _type(copy._type) {
}

Animal& Animal::operator = (const Animal& other) {
	if (this != &other) {
		this->_type = other._type;
	}
	return (*this);
}

Animal::~Animal() {
}

void Animal::makeSound() const {
	std::cout << "Animal noises..." << std::endl;
}

std::string Animal::getType() const {
	return (_type);
}