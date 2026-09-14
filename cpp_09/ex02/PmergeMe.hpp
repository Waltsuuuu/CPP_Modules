#ifndef PMERGE_ME_HPP
# define PMERGE_ME_HPP

#include <vector>
#include <deque>

class PmergeMe {
	private:
		std::vector<int>	_vec;
		std::deque<int>		_deq;

	public:
		PmergeMe();
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);
		~PmergeMe();
};

#endif