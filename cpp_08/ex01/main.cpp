#include "Span.hpp"
#include <iostream>

int main() {
	Span sp(3);

	try {
		sp.addNumber(10);
		sp.addNumber(20);
		sp.addNumber(30);
		sp.addNumber(40);
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}