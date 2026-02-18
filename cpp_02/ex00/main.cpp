#include <iostream>
#include "Fixed.hpp"

int main( void ) {
	std::cout << "1.----\n";
	Fixed a;
	
	std::cout << "2.----\n";
	Fixed b( a );
	
	std::cout << "3.----\n";
	Fixed c;
	
	std::cout << "4.----\n";
	c = b;
	
	std::cout << "\nPrinting values:\n";
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
	return (0);
}