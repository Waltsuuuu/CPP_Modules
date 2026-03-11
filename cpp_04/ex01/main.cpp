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

	std::cout << "\nEND OF MAIN \n" << std::endl;
	
	return (0);
}