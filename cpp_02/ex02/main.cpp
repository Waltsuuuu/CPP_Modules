#include <iostream>
#include "Fixed.hpp"

// void printBits(const Fixed& num)
// {
//     int value = num.getRawBits();

//     for (int i = 31; i >= 0; --i)
//     {
//         std::cout << ((value >> i) & 1);

//         if (i == 8) // boundary between integer and fractional bits
//             std::cout << " | ";
//     }

//     std::cout << std::endl;
// }

int main( void ) {
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	return 0;
}