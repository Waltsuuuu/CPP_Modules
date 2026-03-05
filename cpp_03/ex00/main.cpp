#include "ClapTrap.hpp"
#include <iostream>

int main() {
	ClapTrap david("David");
	ClapTrap goliath("Goliath");

	goliath.attack("David");
	david.takeDamage(5);
	david.beRepaired(5);
	david.attack("Goliath");
	goliath.takeDamage(11);

	ClapTrap idk(david);
	return 0;
}