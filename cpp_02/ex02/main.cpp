#include <iostream>
#include "Fixed.hpp"

int main()
{
	Fixed const a(5);
	Fixed b(2);

	std::cout << Fixed::min(a, b) << std::endl;
	// std::cout << Fixed::max(a, b) << std::endl;
    return 0;
}