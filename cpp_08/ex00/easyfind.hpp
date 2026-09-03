#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <algorithm>
#include <stdexcept>

// The function returns a iterator to the first
// occurrence of the integer in the container.
// If not found, throws an error.
template<typename T>
typename T::iterator easyfind(T& container, int toFind) {
	typename T::iterator it;

	it = std::find(container.begin(), container.end(), toFind);
	
	if (it == container.end())
			throw std::runtime_error("Value not found.");

	return it;
}

#endif