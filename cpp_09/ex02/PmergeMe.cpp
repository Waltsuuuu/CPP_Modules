#include "PmergeMe.hpp"
#include <cstdlib>
#include <climits>
#include <cerrno>
#include <stdexcept>
#include <utility>

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

void PmergeMe::printBefore() const {
	std::cout << "Before: ";
	printContainer(_vec);
	std::cout << std::endl;
}

void PmergeMe::sort() {
	fordJohnson<std::vector<int>, std::vector<std::pair<int, int>>>(_vec);
	// fordJohnson<std::deque<int>,std::deque<std::pair<int, int>>>(_deq);
}

// Generates the order in which pending elements are inserted.
//
// pendingPairs includes b1 at index 0, but b1 is inserted into
// the main chain separately. The returned values are direct
// indexes into pendingPairs.
//
// Jacobsthal numbers divide the pending elements into groups.
// Each group is processed backwards to reduce the number of
// comparisons required during binary insertion.
//
// Example:
// pendingPairs = [b1, b2, b3, b4, b5]
// returned order = [2, 1, 4, 3]
// insertion order = b3, b2, b5, b4
std::vector<size_t> PmergeMe::generateInsertionOrder(size_t pendingSize) const {
	// Jacobsthal sequence begins: 0, 1, 1, 3, 5, 11, 21...
	std::vector<size_t> jacobsthal = {0, 1};

	// Store the final indexes into pendingPairs.
	std::vector<size_t> insertionOrder;

#ifdef DEBUG
	std::cout << "\nGenerating insertion order for "
			  << pendingSize
			  << " pairs\n";
#endif

	// Generate enough Jacobsthal numbers to cover pendingPairs.
	while (jacobsthal.back() < pendingSize) {
		size_t sequenceSize = jacobsthal.size();

		// Jacobsthal formula:
		// J(n) = J(n - 1) + 2 * J(n - 2)
		size_t nextJacobsthal = jacobsthal[sequenceSize - 1] + 2 * jacobsthal[sequenceSize - 2];
		jacobsthal.push_back(nextJacobsthal);

#ifdef DEBUG
		std::cout << "Generated Jacobsthal number: "
				  << nextJacobsthal
				  << '\n';
#endif
	}

#ifdef DEBUG
	std::cout << "Jacobsthal sequence: ";

	for (size_t number : jacobsthal)
		std::cout << number << " ";

	std::cout << '\n';
#endif

	// Use consecutive Jacobsthal numbers as group boundaries.
	for (size_t i = 1; i < jacobsthal.size(); ++i) {
		// The group normally ends at the current Jacobsthal number.
		// std::min() prevents it from going past pendingPairs.
		size_t groupEnd = std::min(jacobsthal[i], pendingSize);

		// The previous Jacobsthal number marks where the preceding
		// group ended.
		size_t previousGroupEnd = jacobsthal[i - 1];

#ifdef DEBUG
		std::cout << "Group between Jacobsthal values "
				  << previousGroupEnd
				  << " and "
				  << jacobsthal[i]
				  << ": ";

		if (jacobsthal[i] > pendingSize)
			std::cout << "(end limited to " << pendingSize << ") ";
#endif

		// Add the indexes in reverse order within this group.
		while (groupEnd > previousGroupEnd) {
			--groupEnd;

			// Index 0 represents b1, which is already in mainChain.
			if (groupEnd > 0) {
				insertionOrder.push_back(groupEnd);

#ifdef DEBUG
				std::cout << groupEnd << " ";
#endif
			}
		}

#ifdef DEBUG
		std::cout << '\n';
#endif
	}

#ifdef DEBUG
	std::cout << "Final insertion indexes: ";

	for (size_t index : insertionOrder)
		std::cout << index << " ";

	std::cout << "\n\n";
#endif

	return insertionOrder;
}
