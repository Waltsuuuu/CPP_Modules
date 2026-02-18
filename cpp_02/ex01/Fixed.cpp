#include "Fixed.hpp"
#include <iostream>

/* Default Constructor
	- Initializes the Fixed object wtih a fixed-point value of 0.
*/
Fixed::Fixed() : _value(0) {
	std::cout << "Default constructor called\n";
}

/* Integer Constructor
	- Converts an integer into a fixed-point represenation.
*/
Fixed::Fixed(int input) : _value(input << _fracBits) {
	std::cout << "Integer constructor called\n";
} 

/* Copy Constructor
	- Creates a new Fixed object by copying 
	  the internal '_value' from another Fixed object.
*/
Fixed::Fixed(const Fixed &copy) : _value(copy._value){
	std::cout << "Copy constructor called\n";
}

/* Copy Assignment Operator ( = operator overload )
	- Assigns the value of one Fixed object to another existing Fixed object.
	- Includes a self-assignment check to avoid unnecessary work.
*/
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

/* Sets the raw fixed-point value stored in the object */
void Fixed::setRawBits( int const raw ) {
	std::cout << "setRawBits member function called\n";
	_value = raw;
}

/* Returns the raw fixed-point value stored in the object */
int Fixed::getRawBits( void ) const {
	std::cout << "getRawBits member function called\n";
	return (_value);
}