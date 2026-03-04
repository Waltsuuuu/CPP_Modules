#include "Fixed.hpp"
#include <iostream>

/* Default Constructor
	- Initializes the Fixed object wtih a fixed-point '_value' of 0.
*/
Fixed::Fixed() : _value(0) {
	std::cout << "Default constructor called\n";
}

/* Destructor */
Fixed::~Fixed() {
	std::cout << "Destructor called\n";
}

/* Copy Constructor
	- Creates a new Fixed object by copying 
	  the internal '_value' from another Fixed object.
*/
Fixed::Fixed(const Fixed &copy) : _value(copy._value){
	std::cout << "Copy constructor called\n";
}

/* Copy Assignment Operator ( = operator overload )
	- Replaces the contents of an EXISTING OBJECT with the contents of 'other'.
*/
Fixed& Fixed::operator=(const Fixed& other) {
	std::cout << "Copy assignment operator called\n";
	// Self assignment guard
	if (this != &other) {
		this->_value = other._value;
	}
	return *this;
}

/* Sets the raw fixed-point '_value' of the object */
void Fixed::setRawBits( int const raw ) {
	std::cout << "setRawBits member function called\n";
	_value = raw;
}

/* Returns the raw fixed-point '_value' of the object */
int Fixed::getRawBits( void ) const {
	std::cout << "getRawBits member function called\n";
	return (_value);
}