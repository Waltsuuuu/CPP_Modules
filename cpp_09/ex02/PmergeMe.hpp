#ifndef PMERGE_ME_HPP
# define PMERGE_ME_HPP

#include <vector>
#include <deque>
#include <iostream>

class PmergeMe {
	private:
		std::vector<int>	_vec;
		std::deque<int>		_deq;

		template <typename Container>
		void printContainer(const Container& container) const;

	public:
		PmergeMe();
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);
		~PmergeMe();

		void parseInput(int argc, char** argv);
		void printBefore() const;
};

#include "PmergeMe.tpp"

#endif