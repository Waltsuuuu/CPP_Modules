#include "Cat.hpp"
#include <iostream>

Cat::Cat() : Animal(), _brain(new Brain()) {
	std::cout << "Cat constructed" << std::endl;
	_type = "Cat";
}

Cat::Cat(const Cat& copy) : Animal(copy), _brain(new Brain(*copy._brain)) {
	std::cout << "Cat copy constructed" << std::endl;
}

Cat& Cat::operator = (const Cat& other) {
	if (this != &other) {
		Animal::operator = (other);
		*_brain = *other._brain;
	}
	std::cout << "Cat assignment operator called" << std::endl;
	return (*this);
}

Cat::~Cat() {
	std::cout << "Cat destructed" << std::endl;
	delete _brain;
}

void Cat::makeSound() const {
	std::cout << "Meow" << std::endl;
}

void Cat::setIdea(int index, const std::string& idea) {
	_brain->setIdea(index, idea);
}

std::string Cat::getIdea(int index) const {
	return (_brain->getIdea(index));
}