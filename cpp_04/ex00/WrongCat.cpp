#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat() : WrongAnimal() {
	std::cout << "WrongCat constructed" << std::endl;
	_type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat& copy) : WrongAnimal(copy) {
	std::cout << "WrongCat copy constructed" << std::endl;
}

WrongCat& WrongCat::operator = (const WrongCat& other) {
	if (this != &other) {
		WrongAnimal::operator = (other);
	}
	std::cout << "WrongCat copy assignment called" << std::endl;
	return (*this);
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat destructed" << std::endl;
}

void WrongCat::makeSound() const {
	std::cout << "Meow" << std::endl;
}