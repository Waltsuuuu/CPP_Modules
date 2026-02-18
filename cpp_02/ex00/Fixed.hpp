#ifndef FIXED_HPP
# define FIXED_HPP

// Stores a number in fixed-point representation.
class Fixed {
	private:
		int 				_value;
		static const int	_fracBits = 8;
	public:
		// Default constructor
		Fixed();

		// Copy constructor (Creates a new object as a copy of an existing one)
		Fixed(const Fixed &copy);

		//Copy assignment operator (Replaces the ontents of an existing object with aothher objects content)
		Fixed& operator=(const Fixed& fixed);

		// Destructor
		~Fixed();

		// Returns the fixed-point value exactly as it is stored.
		int getRawBits( void ) const;

		// Sets the raw value of the fixed-point number
		void setRawBits( int const raw );
};

#endif