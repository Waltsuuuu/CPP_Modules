#ifndef FIXED_HPP
# define FIXED_HPP

/* Blueprint for Fixed-point number class in Orthodox Canonical Form. */
class Fixed {
	private:
		int 				_value;			// Fixed-point representation.
		static const int	_fracBits = 8;	// Number of bits representing the fractional part of '_value'.
	public:
		// Default constructor
		Fixed();

		// Copy constructor
		//  - Creates a NEW OBJECT as a copy of an existing one.
		Fixed(const Fixed &copy);

		//Copy assignment operator
		//  - Replaces the contents of an EXISTING OBJECT with the contents of 'other'.
		Fixed& operator=(const Fixed& other);

		// Destructor
		~Fixed();

		// Returns the raw fixed-point '_value' of the object.
		int getRawBits( void ) const;

		// Sets the raw fixed-point '_value' of the object.
		void setRawBits( int const raw );
};

#endif