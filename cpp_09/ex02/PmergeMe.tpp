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


#endif