#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed() : _value(0) {
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(const Fixed &copy) : _value(copy._value){
	std::cout << "Copy constructor called\n";
}

Fixed& Fixed::operator=(const Fixed& fixed) {
	std::cout << "Copy assignemnt operator called\n";
	// Self assignmnet guard
	if (this != &fixed) {
		this->_value = fixed._value;
	}
	return *this;
}

Fixed::~Fixed() {
	std::cout << "Destructor called\n";
}

int Fixed::getRawBits( void ) const {
	std::cout << "getRawBits member function called\n";
	return (_value);
}

void Fixed::setRawBits( int const raw ) {
	std::cout << "setRawBits member function called\n";
	_value = raw;
}