#ifndef SPAN_HPP
# define SPAN_HPP

#include <vector>

class Span {
	private:
		unsigned int		_maxSize;
		std::vector<int>	_numbers;

	public:
		Span();
		Span(unsigned int N);
		Span(const Span& other);
		Span& operator=(const Span& other);
		~Span();

		void addNumber(int number);

		template <typename Iterator>
		void addNumbers(Iterator begin, Iterator end) {
			for (Iterator it = begin; it != end; ++it)
				addNumber(*it);
		}

		unsigned int longestSpan();
		unsigned int shortestSpan();
};

#endif