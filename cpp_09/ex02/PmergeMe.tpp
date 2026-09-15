#ifndef PMERGEME_TPP
# define PMERGEME_TPP

template <typename Container>
void PmergeMe::printContainer(const Container& container) const {
    bool first = true;

    for (int value : container)
    {
        if (!first)
            std::cout << " ";

        std::cout << value;
        first = false;
    }
}

template <typename Container, typename PairContainer>
void PmergeMe::fordJohnson(Container& container) {
	// Already sorted check.
	if (container.size() <= 1)
		return;

	// Stores each pair as (smaller, larger)
	PairContainer pairs;

	// If odd-size container, save last pairless value in 'straggler'.
	bool hasStraggler = container.size() % 2 != 0;
	int straggler = 0;
	if (hasStraggler)
		straggler = container.back();

	// Create pairs of two adjacent values.
	for (std::size_t i = 0; i + 1 < container.size(); i += 2) {
		int first = container[i];
		int second = container[i + 1];

		// Store as (smaller, larger)
		if (first < second)
			pairs.emplace_back(first, second);
		else
			pairs.emplace_back(second, first);
	}

#ifdef DEBUG
    std::cout << "Pairs:\n";

    for (const std::pair<int, int>& pair : pairs)
    {
        std::cout << "("
                  << pair.first   // Smaller b value
                  << ", "
                  << pair.second  // Larger a value
                  << ")\n";
    }

    if (hasStraggler)
        std::cout << "Straggler: " << straggler << '\n';
#endif

	// Extract the larger value from every pair.
	Container largerValues;
	for (const std::pair<int, int>& pair : pairs)
		largerValues.push_back(pair.second);

#ifdef DEBUG
		std::cout << "Larger values before recursion: ";
		printContainer(largerValues);
		std::cout << '\n';
#endif

	// Recursively apply the same pairing process to the larger values.
	// Each recursive call reduces the problem size by roughly half.
	fordJohnson<Container, PairContainer>(largerValues);

#ifdef DEBUG
    std::cout << "Larger values after recursion: ";
    printContainer(largerValues);
    std::cout << '\n';
#endif

	PairContainer sortedPairs;
	for (int larger : largerValues) {
		for (typename PairContainer::iterator it = pairs.begin(); it != pairs.end(); ++it) {
			if (it->second == larger) {
				sortedPairs.push_back(*it);

				// Prevents the same pair from being matched again.
				pairs.erase(it);
				break;
			}
		}
	}

#ifdef DEBUG
    std::cout << "Pairs after reordering:\n";

    for (const std::pair<int, int>& pair : sortedPairs)
    {
        std::cout << "("
                  << pair.first
                  << ", "
                  << pair.second
                  << ")\n";
    }
#endif

	// Build the initial main chain.
	// The first smaller value can be placed before all sorted larger values
	// because it is smaller than the smallest larger value.
	Container mainChain;
	if (!sortedPairs.empty()) {
		// add b1.
		mainChain.push_back(sortedPairs.front().first);

		// Add all sorted 'a' values.
		for (const std::pair<int, int>& pair : sortedPairs)	
			mainChain.push_back(pair.second);
	}

#ifdef DEBUG
    std::cout << "Initial main chain: ";
    printContainer(mainChain);
    std::cout << '\n';
#endif
}

#endif