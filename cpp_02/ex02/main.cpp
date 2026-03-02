#include <iostream>
#include "Fixed.hpp"

int main( void ) {
	Fixed a;
	Fixed const b( Fixed( 5.0f ) * Fixed( 2 ) );
	std::cout << b << std::endl;
	a = 30;
	std::cout << a + b << std::endl;
	std::cout << a - b << std::endl;
	std::cout << a / b << std::endl;
	if (a > b)
		std::cout << "a is greater than b" << std::endl;
	if (b < a)
		std::cout << "b is less than a" << std::endl;
	// std::cout << ++a << std::endl;
	// std::cout << a << std::endl;
	// std::cout << a++ << std::endl;
	// std::cout << a << std::endl;
	// std::cout << b << std::endl;
	// std::cout << Fixed::max( a, b ) << std::endl;
	return 0;
	}