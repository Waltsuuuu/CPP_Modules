#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie() {
};

Zombie::~Zombie() {
	std::cout << _name << " destroyed\n";
};

void Zombie::setZombieName( std::string name ) {
	_name = name;
}

void Zombie::announce( void ) {
	std::cout << _name << ": BraiiiiiiinnnzzzZ...\n";
}
