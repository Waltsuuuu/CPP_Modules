#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal() : _type("WrongAnimal") {
}

WrongAnimal::WrongAnimal(const WrongAnimal& copy) : _type(copy._type) {
}

WrongAnimal& WrongAnimal::operator = (const WrongAnimal& other) {
	if (this != &other) {
		this->_type = other._type;
	}
	return (*this);
}

WrongAnimal::~WrongAnimal() {
}

void WrongAnimal::makeSound() const {
	std::cout << "WrongAnimal noises..." << std::endl;
}

std::string WrongAnimal::getType() const {
	return (_type);
}