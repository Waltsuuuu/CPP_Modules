#ifndef FIXED_HPP
# define FIXED_HPP
#include <ostream>

class Fixed {
	private:
		int 				_value;			// Fixed-point representation.
		static const int	_fracBits = 8;	// Number of bits representing the fractional part of '_value'.
	public:
	// Constructors
		Fixed();					// Default
		Fixed(int input);			// Integer
		Fixed(float input);			// Float
		Fixed(const Fixed &copy);	// Copy
		
	// Destructor
		~Fixed();

	// '=' Operator overload.
		Fixed& operator = (const Fixed& other);

	// Returns the raw fixed-point '_value' of the object.
		int getRawBits( void ) const;

	// Sets the raw fixed-point '_value' of the object.
		void setRawBits( int const raw );

	// Converts the fixed-point '_value' to an integer representation.
		int toInt( void ) const;

	// Converts the fixed-point '_value' to a float representation.
		float toFloat( void ) const;

};

// '<<' insertion operator overload.
std::ostream& operator << (std::ostream& out, const Fixed& value);

#endif