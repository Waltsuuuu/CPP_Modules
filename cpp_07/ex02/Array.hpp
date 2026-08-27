#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <exception>

// Generic array class.
// Array<int> numbers(5) -- Makes an array that holds 5 ints.
// Array<std::string> names(5) -- Makes an array that holds 5 strings.
template <typename T>
class Array {
	private:
		T*				_data;
		unsigned int	_size;

	public:
		Array();								// Empty array
		Array(unsigned int n);					// Arrat with 'n' elements
		Array(const Array &other);				// Copy constructor
		Array &operator=(const Array& other);	// Assignment operator
		~Array();								// Destructor (frees alloced mem)

		T &operator[](unsigned int index);				// Access array elements (ex. arr[0])
		const T &operator[](unsigned int index) const;	// Indexing a const Array

		unsigned int size() const;				// Returns _size
};

#include "Array.tpp"


#endif