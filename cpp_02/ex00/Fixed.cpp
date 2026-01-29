#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed {
	private:
		int 				_fixed;
		static const int	_fracBits;
	public:
		// Default constructor
		Fixed();
		// Copy constructor (Creates a new object as a copy of an existing one)
		Fixed(const Fixed &copy);
		//Copy assignment operator (Replaces the ontents of an existing object with aothher objects content)
		Fixed& operator= (const Fixed& fixed);
		// Destructor
		~Fixed();

		// Returns value of the fixed-point value
		int getRawBits( void ) const;

		// Sets teg raw value of the fixed-point number
		void setRaBits( int const raw );
};

#endif