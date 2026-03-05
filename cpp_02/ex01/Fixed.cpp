#include "Fixed.hpp"
#include <iostream>
#include <cmath>

/*
    Fixed-point format:
    - Internal storage (_value) is an integer representing a value scaled by 2^_fracBits.
    - Real value ≈ _value / (1 << _fracBits)
*/

// -------------------- Constructors / Destructor --------------------

/* Default Constructor: initializes '_value' to 0 */
Fixed::Fixed() : _value(0) {
	std::cout << "Default constructor called\n";
}

/* Integer Constructor
	- Converts an integer into a fixed-point representation.
	- Left shift bits by 8 (_fracBits) to make room for fractional part.
*/
Fixed::Fixed(int input) : _value(input << _fracBits) {
	std::cout << "Integer constructor called\n";
}

/* Float Constructor
	- Converts a float into a fixed-point representation.
	- Multiplies 'input' by 2^_fracBits to scale it.
	- Rounds the scaled result to the nearest integer.
	- Stores the scaled result as the fixed-point '_value'.
*/
Fixed::Fixed(float input) {
	std::cout << "Float constructor called\n";
	float scaled = input * (1 << _fracBits);
	_value = static_cast<int>(roundf(scaled));
}

/* Copy Constructor
	- Creates a new Fixed object by copying 
	  the internal '_value' from another Fixed object.
*/
Fixed::Fixed(const Fixed &copy) : _value(copy._value){
	std::cout << "Copy constructor called\n";
}

/* Destructor*/
Fixed::~Fixed() {
	std::cout << "Destructor called\n";
}


// -------------------- Conversions --------------------

/* Converts the fixed-point '_value' to floating-point representation */
float Fixed::toFloat( void ) const {
	return (static_cast<float>(_value) / (1 << _fracBits));
}

/* Converts the fixed-point '_value' to integer representation */
int Fixed::toInt( void ) const {
	return (_value >> _fracBits);
}


// -------------------- Raw accessors --------------------

/* Sets the raw fixed-point '_value' stored in the object */
void Fixed::setRawBits( int const raw ) {
	std::cout << "setRawBits member function called\n";
	_value = raw;
}

/* Returns the raw fixed-point '_value' stored in the object */
int Fixed::getRawBits( void ) const {
	std::cout << "getRawBits member function called\n";
	return (_value);
}


// -------------------- Operators --------------------

Fixed& Fixed::operator=(const Fixed& other) {
	std::cout << "Copy assignment operator called\n";
	// Self assignment guard
	if (this != &other) {
		this->_value = other._value;
	}
	return (*this);
}

/* << Insertion operator overload.
	- Takes a reference to a 'std::ostream' object and a reference to the 'Fixed' object value.
	- Converts Fixed object to a float and inserts it into the output stream.
	- Return ostream object (which now includes the fixed-point value).
*/
std::ostream& operator<<(std::ostream& out, const Fixed& fixed) {
	out << fixed.toFloat();
	return (out);
}