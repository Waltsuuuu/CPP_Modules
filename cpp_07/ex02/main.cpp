#include "Array.hpp"
#include <iostream>

int main()
{
	// Empty array
	Array<int> empty;
	std::cout << "Empty size: " << empty.size() << std::endl;

	// Array with 5 ints
	Array<int> numbers(5);

	for (unsigned int i = 0; i < numbers.size(); i++)
		numbers[i] = i * 10;

	std::cout << "Numbers: ";
	for (unsigned int i = 0; i < numbers.size(); i++)
		std::cout << numbers[i] << " ";
	std::cout << std::endl;

	// Copy constructor
	Array<int> copy(numbers);

	copy[0] = 999;

	std::cout << "Original first value: " << numbers[0] << std::endl;
	std::cout << "Copy first value: " << copy[0] << std::endl;

	// Assignment operator
	Array<int> assigned(2);
	assigned = numbers;

	assigned[1] = 555;

	std::cout << "Original second value: " << numbers[1] << std::endl;
	std::cout << "Assigned second value: " << assigned[1] << std::endl;

	// Const Array
	const Array<int> constArray(numbers);

	std::cout << "Const array first value: " << constArray[0] << std::endl;

	// Out of bounds
	try
	{
		std::cout << numbers[100] << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Caught out of bounds exception" << std::endl;
	}

	return 0;
}