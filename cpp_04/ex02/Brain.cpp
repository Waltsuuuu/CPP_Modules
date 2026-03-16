#include "Brain.hpp"
#include <iostream>

Brain::Brain() {
	std::cout << "Brain constructed" << std::endl;
}

Brain::Brain(const Brain& copy) {
	for (int i = 0; i < 100; i++) {
		_ideas[i] = copy._ideas[i];
	}
	std::cout << "Brain copy constructed" << std::endl;
}


Brain& Brain::operator = (const Brain& other) {
	if (this != &other) {
		for (int i = 0; i < 100; i++) {
			_ideas[i] = other._ideas[i];
		} 
	}
	std::cout << "Brain assignment operator called" << std::endl;
	return (*this);
}

Brain::~Brain() {
	std::cout << "Brain Destructed" << std::endl;
}

void Brain::setIdea(int index, const std::string& idea) {
	if (index >= 0 && index <= 99) {
		_ideas[index] = idea;
	}
}

std::string Brain::getIdea(int index) const {
	if (index >= 0 && index <= 99) {
		return (_ideas[index]);
	}
	return ("No ideas here...");
}
