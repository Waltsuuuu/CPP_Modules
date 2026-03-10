#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
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

	std::cout << std::endl;

	const WrongAnimal* wrongAnimalPtr = new WrongAnimal();
	const WrongAnimal* wrongCatPtr = new WrongCat();
	
	std::cout << std::endl;

	std::cout << wrongAnimalPtr->getType() << std::endl;
	std::cout << wrongCatPtr->getType() << std::endl;
	wrongAnimalPtr->makeSound();
	wrongCatPtr->makeSound();
	
	std::cout << std::endl;
	
	dogPtr->makeSound();
	catPtr->makeSound();
	animalPtr->makeSound();
	
	std::cout << std::endl;
	
	
	catObj.makeSound();
	dogObj.makeSound();

	std::cout << std::endl;

	delete animalPtr;
	delete dogPtr;
	delete catPtr;
	delete wrongAnimalPtr;
	delete wrongCatPtr;
	return (0);
}