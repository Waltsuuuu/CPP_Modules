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

	return (0);
}