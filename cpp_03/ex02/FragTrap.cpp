#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap() : ClapTrap() {
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "FragTrap named " << _name << " constructed" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "FragTrap named " << _name << " constructed" << std::endl;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap named " << _name << " destructed" << std::endl;
}

FragTrap::FragTrap(const FragTrap& copy) : ClapTrap(copy) {
	std::cout << "FragTrap " << _name << " copy constructed" << std::endl;
}

FragTrap& FragTrap::operator = (const FragTrap& other) {
	if (this != &other) {
		ClapTrap::operator = (other);
	}
	return (*this);
}

// ---------- Member Functions -----------

void FragTrap::attack(const std::string& target) {
	if (_energyPoints <= 0 || _hitPoints <= 0) {
		std::cout << "FragTrap " << _name 
				  << " does not have enough energy to attack." << std::endl;
		return ;
	}
	_energyPoints--;
	std::cout << "FragTrap " << _name 
			  << " attacks " << target
			  << ", causing " << _attackDamage
			  << " points of damage!" << std::endl;
}

void FragTrap::highFivesGuys(void) {
	std::cout << "FragTrap " << _name 
			  << " is asking to be high-fived ✋!" << std::endl;
}