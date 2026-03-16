#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main()
{
	std::cout << "--- CREATING kitty ---\n" << std::endl; 
	Cat kitty;

	std::cout << "\n--- SETTING and GETTING kitty idea ---\n" << std::endl;
	kitty.setIdea(1, "Bad idea...");
	std::cout << kitty.getIdea(1) << std::endl;
	
	std::cout << "\n--- CREATING kittyTwo BASED ON kitty ---\n" << std::endl; 
	Cat kittyTwo = kitty;

	std::cout << "\n--- GETTING kittyTwo idea ---\n" << std::endl;
	std::cout << kittyTwo.getIdea(1) << std::endl;

	std::cout << "\n--- SETTING kittyTwo IDEA INDEX 1 ---\n" << std::endl;
	kittyTwo.setIdea(1, "Good idea!");
	std::cout << kittyTwo.getIdea(1) << std::endl;

	std::cout << "\n--- CHECKING IF kitty IDEA INDEX 1 CHANGED --- \n" << std::endl; 
	std::cout << kitty.getIdea(1) << std::endl;

	/* -------- SUBJECT REQUIRED TEST -------- */
	std::cout << "\n--- SUBJECT TEST---\n" << std::endl;

	std::cout << "\n--- CREATING ANIMAL ARRAY ---\n" << std::endl;

	const int size = 6;
	Animal* animals[size];

	for (int i = 0; i < size / 2; i++)
	{
		std::cout << "Creating Dog " << i << std::endl;
		animals[i] = new Dog();
	}

	for (int i = size / 2; i < size; i++)
	{
		std::cout << "Creating Cat " << i << std::endl;
		animals[i] = new Cat();
	}

	std::cout << "\n--- DELETING ANIMAL ARRAY ---\n" << std::endl;

	for (int i = 0; i < size; i++)
	{
		std::cout << "Deleting animal " << i << std::endl;
		delete animals[i];
	}

	std::cout << "\nEND OF MAIN\n" << std::endl;

	return (0);
}