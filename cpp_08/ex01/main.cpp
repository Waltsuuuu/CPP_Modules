#include "Span.hpp"

#include <iostream>
#include <vector>

int main() {
	Span sp(5);

	std::vector<int> values;

	values.push_back(6);
	values.push_back(3);
	values.push_back(17);
	values.push_back(9);
	values.push_back(11);

	try {
		sp.addNumbers(values.begin(), values.end());

		std::cout << "Shortest span: "
				  << sp.shortestSpan() << std::endl;

		std::cout << "Longest span: "
				  << sp.longestSpan() << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}