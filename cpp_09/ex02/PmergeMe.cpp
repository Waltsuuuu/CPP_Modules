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
	std::vector<size_t> jacobstahl = {0, 1};

	// Store the final indexes into pendingPairs;
	std::vector<size_t> order;

    // Generate enough Jacobsthal numbers to cover pendingPairs.
	while (jacobstahl.back() < pendingSize) {
		size_t size = jacobstahl.size();

		// Jacobsthal formula:
        // J(n) = J(n - 1) + 2 * J(n - 2)
		jacobstahl.push_back(jacobstahl[size - 1] + 2 * jacobstahl[size - 2]);
	}

	// Use consecutive Jacobstahl nummbers as group boundaries.
	for (size_t i = 1; i < jacobstahl.size(); ++i) {
		// End the group at the current Jacobsthal number.
        // If that number is larger than pendingPairs, stop at
        // the actual end of pendingPairs instead.
		size_t end = std::min(jacobstahl[i], pendingSize);

		// The previous Jacobstahl number marks where the preceding group ended.
		size_t start = jacobstahl[i - 1];

		// Add the indexes in revers order withing this group
		while (end > start) {
			--end;

			// Index 0 is b1 which is inserted separately.
			if (end > 0)
				order.push_back(end);
		}
	}

	return order;
}
