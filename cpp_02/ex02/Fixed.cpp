#include "Fixed.hpp"
#include <iostream>
#include <cmath>

/* Default Constructor
	- Initializes the Fixed object wtih a fixed-point value of 0.
*/
Fixed::Fixed() : _value(0) {
}

/* Integer Constructor
	- Converts an integer into a fixed-point representation.
	- Left shift bits by 8 (_fracBits) to make room for fractional part.
*/
Fixed::Fixed(int input) : _value(input << _fracBits) {
}

/* Float Constructor
	- Converts a float into a fixed-point representation.
	- Multiplies the float (input) by 2^_fracBits to scale it.
	- Rounds the result to the nearest integer.
	- Stores the result as the fixed-point value.
*/
Fixed::Fixed(float input) {
	float scaled = input * (1 << _fracBits);
	_value = static_cast<int>(roundf(scaled));
}

/* Copy Constructor
	- Creates a new Fixed object by copying 
	  the internal '_value' from another Fixed object.
*/
Fixed::Fixed(const Fixed &copy) : _value(copy._value){
}

/* Fixed Object Destructor*/
Fixed::~Fixed() {
}

// -------------- MEMBER FUNCTIONS

/* Converts the fixed-point value to a float representation
*/
float Fixed::toFloat( void ) const {
	return (static_cast<float>(_value) / (1 << _fracBits));
}

/* Converts the fixed-point value to an integer representation 
   by removing the fractional bits.
	- Right shift bits by 8 (_fracBits), truncating the fractional part.
*/
int Fixed::toInt( void ) const {
	return (_value >> _fracBits);
}

/* Sets the raw fixed-point value stored in the object */
void Fixed::setRawBits( int const raw ) {
	_value = raw;
}

/* Returns the raw fixed-point value stored in the object */
int Fixed::getRawBits( void ) const {
	return (_value);
}

// -------------- OPERATOR OVERLOAD

/* Copy Assignment Operator ( = operator overload )
	- Assigns the value of one Fixed object to another existing Fixed object.
	- Includes a self-assignment check to avoid unnecessary work.
*/
Fixed& Fixed::operator=(const Fixed& fixed) {
	// Self assignment guard
	if (this != &fixed) {
		this->_value = fixed._value;
	}
	return (*this);
}

/* << Insertion operator overload.
	- Takes a reference to a std::ostream object and a reference to the Fixed object value.
	- Converts Fixed object to a float and inserts it into the output stream.
	- Return ostream object (which now includes the fixed-point value).
*/
std::ostream& operator<<(std::ostream& out, const Fixed& value) {
	out << value.toFloat();
	return (out);
}

Fixed Fixed::operator * (const Fixed& other) {
	return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator + (const Fixed& other) {
	return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator - (const Fixed& other) {
	return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator / (const Fixed& other) {
	return Fixed(this->toFloat() / other.toFloat());
}

bool Fixed::operator > (const Fixed& other) const {
	return (this->toFloat() > other.toFloat());
}

bool Fixed::operator < (const Fixed& other) const {
	return (other > *this);
}

bool Fixed::operator == (const Fixed& other) const {
	return (this->toFloat() == other.toFloat());
}