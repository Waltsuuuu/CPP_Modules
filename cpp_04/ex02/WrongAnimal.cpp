#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal() : _type("WrongAnimal") {
	std::cout << "WrongAnimal constructed" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& copy) : _type(copy._type) {
	std::cout << "WrongAnimal copy constructed" << std::endl;
}

WrongAnimal& WrongAnimal::operator = (const WrongAnimal& other) {
	if (this != &other) {
		this->_type = other._type;
	}
	std::cout << "WrongAnimal copy assignment called" << std::endl;
	return (*this);
}

WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal destructed" << std::endl;
}

void WrongAnimal::makeSound() const {
	std::cout << "WrongAnimal noises..." << std::endl;
}

std::string WrongAnimal::getType() const {
	return (_type);
}