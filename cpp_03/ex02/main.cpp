#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

int main() {
	ClapTrap david("David");
	ScavTrap goliath("Goliath");
	FragTrap randomdude("randomDude");

	std::cout << std::endl;

	goliath.attack("David");
	david.takeDamage(20);
	david.beRepaired(5);
	david.attack("Goliath");
	goliath.guardGate();
	randomdude.attack("Goliath");
	goliath.takeDamage(20);
	randomdude.highFivesGuys();
	
	std::cout << std::endl;

	return 0;
}