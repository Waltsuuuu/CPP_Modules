#include "Zombie.hpp"
#include <iostream>

int	main() {
	Zombie *heapZombie = newZombie("heap_zombie");

	heapZombie->announce();

	randomChump("stack_zombie");

	delete heapZombie;
	return (0);
}