#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int main() {
	ClapTrap david("David");
	ScavTrap goliath("Goliath");

	goliath.attack("David");
	david.takeDamage(20);
	david.beRepaired(5);
	david.attack("Goliath");
	goliath.guardGate();
	return 0;
}