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

}

#endif