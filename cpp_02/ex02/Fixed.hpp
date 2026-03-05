#ifndef FIXED_HPP
# define FIXED_HPP
#include <ostream>

/*
    Fixed-point format:
    - Internal storage (_value) is an integer representing a value scaled by 2^_fracBits.
    - Real value ≈ _value / (1 << _fracBits)
*/
class Fixed {
	private:
		int 				_value;			// Fixed-point representation.
		static const int	_fracBits = 8;	// Number of bits representin the fractional part of '_value'.
	public:
	// Constructors
		Fixed();					// Default
		Fixed(int input);			// Integer
		Fixed(float input);			// Float
		Fixed(const Fixed &copy);	// Copy
		
	// Destructor
		~Fixed();

	// Operator overload.
		Fixed&	operator = (const Fixed& fixed);
		Fixed	operator * (const Fixed& other) const;
		Fixed	operator + (const Fixed& other) const;
		Fixed	operator - (const Fixed& other) const;
		Fixed	operator / (const Fixed& other) const;
		// Pre-increment/decrement
		Fixed&	operator ++ ();
		Fixed&	operator -- ();
		// Post-increment/decrement
		Fixed	operator ++ (int);
		Fixed	operator -- (int);
		bool	operator > (const Fixed& other) const;
		bool	operator >= (const Fixed& other) const; 
		bool	operator < (const Fixed& other) const;
		bool	operator <= (const Fixed& other) const;
		bool	operator == (const Fixed& other) const;
		bool	operator != (const Fixed& other) const;
	
	// Returns a reference to the smallest of the input.
		static Fixed&		min(Fixed& a, Fixed& b);
		static const Fixed&	min(const Fixed& a, const Fixed& b);

	// Returns a reference to the largest of the input.
		static Fixed&		max(Fixed& a, Fixed& b);
		static const Fixed& max(const Fixed& a, const Fixed& b);

	// Returns the raw fixed-point '_value' of the object.
		int		getRawBits( void ) const;

	// Sets the raw fixed-point '_value' of the object. 
		void	setRawBits( int const raw );

	// Converts the fixed-point '_value' to an integer representation.
		int		toInt( void ) const;

	// Converts the fixed-point '_value' to a float representation.
		float	toFloat( void ) const;
};

// '<<' insertion operator overload.
std::ostream& operator << (std::ostream& out, const Fixed& fixed);

#endif