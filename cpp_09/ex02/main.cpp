#include "PmergeMe.hpp"
#include <iostream>
#include <exception>

int main(int argc, char** argv) {
	try {
		PmergeMe sorter;

		sorter.parseInput(argc, argv);
	}
	catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
		return 1;
	}
	return 0;
}