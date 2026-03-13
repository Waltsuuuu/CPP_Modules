#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

int main() {
	std::cout << "\n---CLAP TRAP SPAWN---\n" << std::endl;
	ClapTrap david("David");
	ScavTrap goliath("Goliath");
	FragTrap randomdude("randomDude");
	std::cout << std::endl;

	std::cout << "--BATTLE COMMENCE--!\n" << std::endl;
	goliath.attack("David");
	david.takeDamage(20);
	david.beRepaired(5);
	david.attack("Goliath");
	goliath.guardGate();
	randomdude.attack("Goliath");
	goliath.takeDamage(30);
	randomdude.highFivesGuys();
	std::cout << std::endl;

	std::cout << "---END---\n" << std::endl;
	return 0;
}