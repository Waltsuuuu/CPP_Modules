#include "Array.hpp"

// Default constructor.
// Empty array with size 0;
template <typename T>
Array<T>::Array() : _data(NULL), _size(0) {}

// Parameterized constructor.
// Creates an array with 'n' default-initialized elements.
template <typename T>
Array<T>::Array(unsigned int n) : _data(new T[n]()), _size(n) {}

// Copy cnstructor.
// Creates a dee copy of another Array
template <typename T>
Array<T>::Array(const Array& other) : _data(NULL), _size(other._size) {
	if (_size > 0) {
		_data = new T[_size];
		for (unsigned int i = 0; i < _size; i++)
			_data[i] = other._data[i];
	}
}

// Assignment operator
// Repaces this Arrays content with a deep coopy of another Array
template <typename T>
Array<T> &Array<T>::operator=(const Array &other) {
	if (this != &other) {
		delete[] _data; // Delete old data.

		_size = other._size;
		_data = NULL;

		if (_size > 0) {
			_data = new T[_size];
			for (unsigned int i = 0; i < _size; i++)
				_data[i] = other._data[i];
		}
	}
	return *this;
}

// Destructor
// Frees dynamically allocated array
template <typename T>
Array<T>::~Array() {
	delete[] _data;
}

// Access an element at the given index
// Throws if index is out of bounds.
template <typename T>
T &Array<T>::operator[](unsigned int index) {
	if (index >= _size)
		throw std::exception();

	return _data[index];
}

// Access element from a const Array
// Throws if index is out of bounds.
template <typename T>
const T &Array<T>::operator[](unsigned int index) const {
	if (index >= _size)
		throw std::exception();

	return _data[index];
}

// Returns the number of elements in the Array
template <typename T>
unsigned int Array<T>::size() const {
	return _size;
}