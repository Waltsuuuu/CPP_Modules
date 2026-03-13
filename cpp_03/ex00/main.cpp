#include "ClapTrap.hpp"
#include <iostream>

int main() {
	std::cout << "\n---CLAP TRAP SPAWN---\n" << std::endl;
	ClapTrap david("David");
	ClapTrap goliath("Goliath");
	std::cout << std::endl;

	std::cout << "--BATTLE COMMENCE--!\n" << std::endl;
	goliath.attack("David");
	david.takeDamage(5);
	david.beRepaired(5);
	david.attack("Goliath");
	goliath.takeDamage(11);
	goliath.beRepaired(5);
	std::cout << std::endl;

	std::cout << "--OTHER TESTS---\n" << std::endl;
	ClapTrap davidCopy(david);
	ClapTrap noName;
	noName = davidCopy;
	std::cout << std::endl;

	std::cout << "--END--\n" << std::endl;
	return 0;
}