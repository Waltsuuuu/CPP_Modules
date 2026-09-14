#include "PmergeMe.hpp"
#include <cstdlib>
#include <climits>
#include <cerrno>
#include <stdexcept>

// OCF
PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other) : _vec(other._vec), _deq(other._deq) {}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
    if (this != &other)
    {
        _vec = other._vec;
        _deq = other._deq;
    }

    return *this;
}

PmergeMe::~PmergeMe(){}

// ------------------------------------------------- //

void PmergeMe::parseInput(int argc, char** argv) {
	if (argc < 2)
		throw std::invalid_argument("no input provided.");

	for (int i = 1; i < argc; ++i) {
		std::string input = argv[i];
		if (input.empty())
			throw std::invalid_argument("empty input not allowed.");

		// Input must contain only digits.
		for (char c : input) {
			if (!std::isdigit(c))
				throw std::invalid_argument("input contains non digit character.");
		}

		long value = std::stol(input);

		// Input must be positive and fit in an int
		if (value <= 0 || value > INT_MAX)
			throw std::invalid_argument("input must be between 0 and 2147483647.");

		// Store value in both containers
		_vec.push_back(value);
		_deq.push_back(value);
	}
}