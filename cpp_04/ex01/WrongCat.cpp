#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat() : WrongAnimal() {
	_type = "WrongWrongCat";
}

WrongCat::WrongCat(const WrongCat& copy) : WrongAnimal(copy) {
}

WrongCat& WrongCat::operator = (const WrongCat& other) {
	if (this != &other) {
		WrongAnimal::operator = (other);
	}
	return (*this);
}

void WrongCat::makeSound() const {
	std::cout << "Meow" << std::endl;
}