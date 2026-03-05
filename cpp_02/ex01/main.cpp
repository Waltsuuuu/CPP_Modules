#include <iostream>
#include "Fixed.hpp"
#include <iomanip>

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
	Fixed const b( 10 );
	Fixed const c( 42.42f );
	Fixed const d( b );
	a = Fixed( 1234.4321f );
	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;
	return 0;
}