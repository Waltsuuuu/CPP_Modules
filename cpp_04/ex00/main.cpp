#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main()
{
	const Animal* animalPtr = new Animal();
	const Animal* dogPtr = new Dog();
	const Animal* catPtr = new Cat();
	const Cat catObj;
	const Dog dogObj;

	std::cout << animalPtr->getType() << std::endl;
	std::cout << dogPtr->getType() << std::endl;
	std::cout << catPtr->getType() << std::endl;
	
	std::cout << std::endl;
	
	dogPtr->makeSound();
	catPtr->makeSound();
	animalPtr->makeSound();
	
	std::cout << std::endl;
	
	catObj.makeSound();
	dogObj.makeSound();
	delete animalPtr;
	delete dogPtr;
	delete catPtr;
	return (0);
}