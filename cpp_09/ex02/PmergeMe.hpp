#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <vector>
#include <deque>
#include <iostream>

class PmergeMe {
	private:
		std::vector<int>	_vec;
		std::deque<int>		_deq;

		template <typename Container>
		void printContainer(const Container& container) const;

		template <typename Container, typename PairContainer>
		void fordJohnson(Container& container);
		std::vector<size_t> generateInsertionOrder(size_t pendingSize) const;

	public:
		PmergeMe();
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);
		~PmergeMe();

		void parseInput(int argc, char** argv);
		void printBefore() const;
		void sort();
};

#include "PmergeMe.tpp"

#endif