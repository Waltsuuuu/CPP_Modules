#ifndef FIXED_HPP
# define FIXED_HPP
#include <ostream>

class Fixed {
	private:
		int 				_value;
		static const int	_fracBits = 8;
	public:
	// Constructors
		Fixed();
		Fixed(int input);
		Fixed(float input);
		Fixed(const Fixed &copy);
		
	// Destructor
		~Fixed();

	// '=' Operator overload.
		Fixed& operator = (const Fixed& fixed);
		Fixed& operator << (const Fixed& fixed);

	// '*' Operator overload.
		Fixed operator * (const Fixed& other);

	// '+' Operator overload.
		Fixed operator + (const Fixed& other);

	// '-' Operator overload.
		Fixed operator - (const Fixed& other);

	// '/' Operator overload.
		Fixed operator / (const Fixed& other);

	// '>' Operator overload.
		bool operator > (const Fixed& other) const;

	// '<' Operator overload.
		bool operator < (const Fixed& other) const;

	// '==' Operator overload.
		bool operator == (const Fixed& other) const;

	// Returns the '_value' exactly as it is stored.
		int getRawBits( void ) const;

	// Sets the '_value' of the fixed-point number.
		void setRawBits( int const raw );

	// Converts the fixed-point '_value' to an integer representation.
		int toInt( void ) const;

	// Converts the fixed-point '_value' to a float representation.
		float toFloat( void ) const;

};

// '<<' insertion operator overload.
std::ostream& operator << (std::ostream& out, const Fixed& value);

#endif