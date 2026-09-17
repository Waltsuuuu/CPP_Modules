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
#ifdef DEBUG
	std::cout << "\nFJ CALL: ";
	printContainer(container);
	std::cout << std::endl;
#endif
	// Already sorted check.
	if (container.size() <= 1) {
#ifdef DEBUG
		std::cout << "\nBASE CASE REACHED\n" << std::endl;
#endif
		return;
	}

	// Stores each pair as (smaller, larger)
	// (b1, a1)
	// (b2, a2)
	// (b3, a3) ...
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

	std::vector<size_t> insertionOrder = generateInsertionOrder(sortedPairs.size());

#ifdef DEBUG
	std::cout << "Insertion order: ";
	printContainer(insertionOrder);
	std::cout << '\n';
#endif

	// Track the current index of each a value in mainChain.
	//
	// Initially:
	// mainChain = [b1, a1, a2, a3, ...]
	//
	// Therefore:
	// a1 is at index 1
	// a2 is at index 2
	// a3 is at index 3
	std::vector<size_t> partnerPositions(sortedPairs.size());

	for (size_t i = 0; i < sortedPairs.size(); ++i)
			partnerPositions[i] = i + 1;
	
	// Insert the remaining 'b' values in Jacobstahl order.
	for (size_t pairIndex : insertionOrder) {
		int pendingValue = sortedPairs[pairIndex].first;

		// The pending value only needs to be compared against values
		// before its paired a value.
		typename Container::iterator searchEnd = mainChain.begin() + partnerPositions[pairIndex];

		typename Container::iterator insertionPoint = std::lower_bound(mainChain.begin(), searchEnd, pendingValue);

		// Save the index before insertion invalidates iterator.
		size_t insertionIndex = insertionPoint - mainChain.begin();

#ifdef DEBUG
		std::cout << "Inserting b" << pairIndex + 1
				  << " = " << pendingValue
				  << " before partner "
				  << sortedPairs[pairIndex].second
				  << '\n';
#endif

		mainChain.insert(insertionPoint, pendingValue);

		// The insertion shifts every a partner at or after the
		// insertion position one place to the right.
		for (std::size_t i = 0; i < partnerPositions.size(); ++i) {
			if (partnerPositions[i] >= insertionIndex)
				++partnerPositions[i];
		}

#ifdef DEBUG
		std::cout << "Main chain: ";
		printContainer(mainChain);
		std::cout << '\n';
#endif
	}

	// The straggler does not have an a partner, so search the
	// entire chain for its correct insertion position.
	if (hasStraggler) {
		typename Container::iterator insertionPoint =
			std::lower_bound(
				mainChain.begin(),
				mainChain.end(),
				straggler
			);

#ifdef DEBUG
		std::cout << "Inserting straggler: "
				  << straggler << '\n';
#endif

		mainChain.insert(insertionPoint, straggler);

#ifdef DEBUG
		std::cout << "Main chain after straggler: ";
		printContainer(mainChain);
		std::cout << '\n';
#endif
	}

	// Return this recursion level's completed sorted chain
	// through the reference parameter.
	container = mainChain;

#ifdef DEBUG
	std::cout << "FJ RESULT: ";
	printContainer(container);
	std::cout << '\n';
#endif
}

#endif