#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap()
	: 	_name("NoName"), 
		_hitPoints(10),
		_energyPoints(10),
		_attackDamage(0) {
	std::cout << "ClapTrap named " << _name << " constructed" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
	: 	_name(name), 
		_hitPoints(10),
		_energyPoints(10),
		_attackDamage(0) {
	std::cout << "ClapTrap named " << _name << " constructed" << std::endl;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap named " << _name << " destructed" << std::endl;

}

ClapTrap::ClapTrap(const ClapTrap& copy) 
	:	_name(copy._name), 
		_hitPoints(copy._hitPoints),
		_energyPoints(copy._energyPoints),
		_attackDamage(copy._attackDamage) {
	std::cout << "ClapTrap " << _name << " copy constructed" << std::endl;
}

ClapTrap& ClapTrap::operator = (const ClapTrap& other) {
	if (this != &other) {
		this->_name = other._name;
		_hitPoints = other._hitPoints;
        _energyPoints = other._energyPoints;
        _attackDamage = other._attackDamage;
	}
	return (*this);
}

// ---------- Member Functions -----------

void ClapTrap::attack(const std::string& target) {
	if (_energyPoints <= 0 || _hitPoints <= 0) {
		std::cout << "ClapTrap " << _name 
				  << " does not have enough energy/hp to attack." << std::endl;
		return ;
	}
	_energyPoints--;
	std::cout << "ClapTrap " << _name 
			  << " attacks " << target
			  << ", causing " << _attackDamage
			  << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (_hitPoints <= 0) {
		std::cout << "ClapTrap " << _name 
				  << " is already dead." << std::endl;
		return ;
	}
	_hitPoints -= amount;
	std::cout << "ClapTrap " << _name
			  << " took " << amount
			  << " points of damage." << std::endl; 
	if (_hitPoints <= 0) {
		std::cout << "ClapTrap " << _name 
				 << " is now dead." << std::endl;
		return ;
	}
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (_energyPoints <= 0 || _hitPoints <= 0) {
		std::cout << "ClapTrap " << _name << " does not have enough energy/hp to repair." << std::endl;
		return ;
	}
	_energyPoints--;
	_hitPoints += amount;
	std::cout << "ClapTrap " << _name
			  << " regained " << amount
			  << " hit points." << std::endl;
}