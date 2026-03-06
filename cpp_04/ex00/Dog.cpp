#include "Dog.hpp"
#include <iostream>

Dog::Dog() : Animal() {
	_type = "Dog";
}

void Dog::makeSound() const {
	std::cout << "Woof woof" << std::endl;
}