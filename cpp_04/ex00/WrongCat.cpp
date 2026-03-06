#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat() : WrongAnimal() {
	_type = "WrongCat";
}

void WrongCat::makeSound() const {
	std::cout << "Meow" << std::endl;
}