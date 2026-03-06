#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main()
{
	const Animal* animalPtr = new Animal();
	const Animal* dogPtr = new Dog();
	const Animal* catPtr = new Cat();
	const Cat cat;

	std::cout << animalPtr->getType() << std::endl;
	std::cout << dogPtr->getType() << " " << std::endl;
	std::cout << catPtr->getType() << " " << std::endl;
	dogPtr->makeSound();
	catPtr->makeSound();
	animalPtr->makeSound();
	cat.makeSound();
	return (0);
}