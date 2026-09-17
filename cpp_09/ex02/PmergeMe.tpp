#ifndef PMERGEME_TPP
# define PMERGEME_TPP

template <typename Container>
void PmergeMe::printContainer(const Container& values) const {
	bool isFirstValue = true;

	for (const auto& value : values) {
		if (!isFirstValue)
			std::cout << " ";

		std::cout << value;
		isFirstValue = false;
	}
}

template <typename Container, typename PairContainer>
void PmergeMe::fordJohnson(Container& values) {
#ifdef DEBUG
	std::cout << "\nFJ CALL: ";
	printContainer(values);
	std::cout << std::endl;
#endif

	// A container with zero or one value is already sorted.
	// This also stops the recursive calls.
	if (values.size() <= 1) {
#ifdef DEBUG
		std::cout << "\nBASE CASE REACHED\n" << std::endl;
#endif
		return;
	}

	// Store each adjacent pair as (smaller, larger).
	//
	// pair.first  = smaller 'b' value
	// pair.second = larger 'a' value
	//
	// (b1, a1)
	// (b2, a2)
	// (b3, a3) ...
	PairContainer orderedPairs;

	// An odd-sized container has one value without a partner.
	// Save it so it can be inserted into the sorted chain later.
	bool hasUnpairedValue = values.size() % 2 != 0;
	int unpairedValue = 0;

	if (hasUnpairedValue)
		unpairedValue = values.back();

	// Divide the input into adjacent pairs and order each pair (smaller, larger).
	for (std::size_t index = 0; index + 1 < values.size(); index += 2) {
		int leftValue = values[index];
		int rightValue = values[index + 1];

		if (leftValue < rightValue)
			orderedPairs.emplace_back(leftValue, rightValue);
		else
			orderedPairs.emplace_back(rightValue, leftValue);
	}

#ifdef DEBUG
	std::cout << "Ordered pairs:\n";

	for (const std::pair<int, int>& pair : orderedPairs) {
		std::cout << "(" << pair.first << ", " << pair.second << ")\n";
	}

	if (hasUnpairedValue)
		std::cout << "Unpaired value: " << unpairedValue << '\n';
#endif

	// Collect the larger a value from every pair.
	//
	// Example:
	// orderedPairs = [(2, 8), (1, 5), (4, 7)]
	// largerValues = [8, 5, 7]
	Container largerValues;

	for (const std::pair<int, int>& pair : orderedPairs)
		largerValues.push_back(pair.second);

#ifdef DEBUG
	std::cout << "Larger values before recursion: ";
	printContainer(largerValues);
	std::cout << '\n';
#endif

	// Recursively sort the larger values.
	// Each call receives roughly half as many values.
	fordJohnson<Container, PairContainer>(largerValues);

#ifdef DEBUG
	std::cout << "Larger values after recursion: ";
	printContainer(largerValues);
	std::cout << '\n';
#endif

	// Reorder the original pairs to follow the sorted order
	// of their larger values.
	//
	// Original pairs:      [(2, 8), (1, 5), (4, 7)]
	// Sorted larger values: [5, 7, 8]
	// Reordered pairs:     [(1, 5), (4, 7), (2, 8)]
	PairContainer pairsInLargerValueOrder;

	for (int sortedLargerValue : largerValues) {
		for (typename PairContainer::iterator pairIt = orderedPairs.begin(); pairIt != orderedPairs.end(); ++pairIt) {
			if (pairIt->second == sortedLargerValue) {
				pairsInLargerValueOrder.push_back(*pairIt);

				// Remove the matched pair so it cannot be matched
				// again when duplicate larger values exist.
				orderedPairs.erase(pairIt);
				break;
			}
		}
	}

#ifdef DEBUG
	std::cout << "Pairs in larger-value order:\n";

	for (const std::pair<int, int>& pair : pairsInLargerValueOrder)
		std::cout << "(" << pair.first << ", " << pair.second << ")\n";
#endif

	// Build the initial sorted main chain.
	//
	// The larger a values are sorted:
	// a1 <= a2 <= a3 ...
	//
	// We also know b1 <= a1 because they belong to the same pair.
	// Therefore, this chain is already sorted:
	// [b1, a1, a2, a3 ...]
	Container mainChain;

	if (!pairsInLargerValueOrder.empty()) {
		// Place b1 at the beginning.
		mainChain.push_back(pairsInLargerValueOrder.front().first);

		// Add all sorted a values after b1.
		for (const std::pair<int, int>& pair : pairsInLargerValueOrder)
			mainChain.push_back(pair.second);
	}

#ifdef DEBUG
	std::cout << "Initial main chain: ";
	printContainer(mainChain);
	std::cout << '\n';
#endif

	// Generate the pair indexes for the remaining b values.
	//
	// pairs:            [pair1, pair2, pair3, pair4, pair5]
	// smaller values:   [b1,    b2,    b3,    b4,    b5]
	// returned indexes: [2, 1, 4, 3]
	// insertion order:  b3, b2, b5, b4
	std::vector<std::size_t> pendingPairIndexes = generateInsertionOrder(pairsInLargerValueOrder.size());

#ifdef DEBUG
	std::cout << "Pending pair indexes: ";
	printContainer(pendingPairIndexes);
	std::cout << '\n';
#endif

	// Store the current index of every larger a value in mainChain.
	//
	// Initially:
	// mainChain = [b1, a1, a2, a3 ...]
	//
	// a1 is at index 1
	// a2 is at index 2
	// a3 is at index 3
	std::vector<std::size_t> largerPartnerIndexes(pairsInLargerValueOrder.size());

	for (std::size_t pairIndex = 0; pairIndex < pairsInLargerValueOrder.size(); ++pairIndex)
		largerPartnerIndexes[pairIndex] = pairIndex + 1;

	// Insert the remaining b values in Jacobsthal order.
	for (std::size_t pairIndex : pendingPairIndexes) {
		int smallerValueToInsert = pairsInLargerValueOrder[pairIndex].first;

		// We already know that the smaller value is less than or
		// equal to its larger partner. It cannot belong after that
		// partner, so binary search only needs to examine the part
		// of the chain before it.
		typename Container::iterator searchRangeEnd = mainChain.begin() + largerPartnerIndexes[pairIndex];
		typename Container::iterator insertPosition = std::lower_bound(mainChain.begin(), searchRangeEnd, smallerValueToInsert);

		// Save the index before insert() invalidates the iterator.
		std::size_t newValueIndex = insertPosition - mainChain.begin();

#ifdef DEBUG
		std::cout << "Inserting b" << pairIndex + 1
				  << " = " << smallerValueToInsert
				  << " before its larger partner "
				  << pairsInLargerValueOrder[pairIndex].second
				  << '\n';
#endif

		mainChain.insert(insertPosition, smallerValueToInsert);

		// Inserting a value shifts every larger partner at or after
		// the insertion position one place to the right.
		for (std::size_t pairIndexToUpdate = 0; pairIndexToUpdate < largerPartnerIndexes.size(); ++pairIndexToUpdate) {
			if (largerPartnerIndexes[pairIndexToUpdate] >= newValueIndex)
				++largerPartnerIndexes[pairIndexToUpdate];
		}

#ifdef DEBUG
		std::cout << "Main chain: ";
		printContainer(mainChain);
		std::cout << '\n';
#endif
	}

	// The unpaired value has no larger partner, so search the
	// entire main chain to find its correct position.
	if (hasUnpairedValue) {
		typename Container::iterator insertPosition = std::lower_bound(mainChain.begin(), mainChain.end(), unpairedValue);

#ifdef DEBUG
		std::cout << "Inserting unpaired value: " << unpairedValue << '\n';
#endif

		mainChain.insert(insertPosition, unpairedValue);

#ifdef DEBUG
		std::cout << "Main chain after unpaired value: ";
		printContainer(mainChain);
		std::cout << '\n';
#endif
	}

	// Store this recursion level's finished result in the original
	// container so it is available to the previous recursive call.
	values = mainChain;

#ifdef DEBUG
	std::cout << "FJ RESULT: ";
	printContainer(values);
	std::cout << '\n';
#endif
}

#endif