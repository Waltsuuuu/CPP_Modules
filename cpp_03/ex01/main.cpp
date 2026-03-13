#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int main() {
	std::cout << "\n---CLAP TRAP SPAWN---\n" << std::endl;
	ClapTrap david("David");
	ScavTrap goliath("Goliath");
	std::cout << std::endl;

	std::cout << "--BATTLE COMMENCE--!\n" << std::endl;
	goliath.attack("David");
	david.takeDamage(20);
	david.beRepaired(5);
	david.attack("Goliath");
	goliath.guardGate();
	std::cout << std::endl;

	std::cout << "---END---\n" << std::endl;
	return 0;
}