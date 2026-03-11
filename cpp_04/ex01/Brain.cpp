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
	return (*this);
}

Brain::~Brain() {
	std::cout << "Brain Destructed" << std::endl;
}
