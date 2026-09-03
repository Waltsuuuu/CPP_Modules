#include "Span.hpp"

#include <iostream>
#include <vector>

static void printHeader(const std::string& title) {
	std::cout << "\n========================================\n";
	std::cout << title << std::endl;
	std::cout << "========================================\n";
}

int main() {
	printHeader("TEST 1: Basic span calculation");

	try {
		Span sp(5);

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << "Expected shortest span: 2" << std::endl;
		std::cout << "Actual shortest span:   "
				  << sp.shortestSpan() << std::endl;

		std::cout << "Expected longest span: 14" << std::endl;
		std::cout << "Actual longest span:   "
				  << sp.longestSpan() << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}


	printHeader("TEST 2: Adding too many numbers");

	try {
		Span sp(3);

		sp.addNumber(10);
		sp.addNumber(20);
		sp.addNumber(30);

		std::cout << "Span is full. Trying to add 40..." << std::endl;

		sp.addNumber(40);

		std::cout << "ERROR: Exception was not thrown." << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << "Caught expected exception: "
				  << e.what() << std::endl;
	}


	printHeader("TEST 3: Empty Span");

	try {
		Span sp(5);

		std::cout << "Trying shortestSpan() on empty Span..." << std::endl;
		std::cout << sp.shortestSpan() << std::endl;

		std::cout << "ERROR: Exception was not thrown." << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << "Caught expected exception: "
				  << e.what() << std::endl;
	}


	printHeader("TEST 4: Span with one number");

	try {
		Span sp(5);

		sp.addNumber(42);

		std::cout << "Trying longestSpan() with one number..." << std::endl;
		std::cout << sp.longestSpan() << std::endl;

		std::cout << "ERROR: Exception was not thrown." << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << "Caught expected exception: "
				  << e.what() << std::endl;
	}


	printHeader("TEST 5: Duplicate values");

	try {
		Span sp(5);

		sp.addNumber(10);
		sp.addNumber(20);
		sp.addNumber(20);
		sp.addNumber(50);

		std::cout << "Expected shortest span: 0" << std::endl;
		std::cout << "Actual shortest span:   "
				  << sp.shortestSpan() << std::endl;

		std::cout << "Expected longest span: 40" << std::endl;
		std::cout << "Actual longest span:   "
				  << sp.longestSpan() << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}


	printHeader("TEST 6: Range insertion with iterators");

	try {
		Span sp(6);

		std::vector<int> values;
		values.push_back(100);
		values.push_back(200);
		values.push_back(50);
		values.push_back(400);
		values.push_back(300);
		values.push_back(250);

		sp.addNumbers(values.begin(), values.end());

		std::cout << "Inserted 6 numbers using iterator range." << std::endl;

		std::cout << "Expected shortest span: 50" << std::endl;
		std::cout << "Actual shortest span:   "
				  << sp.shortestSpan() << std::endl;

		std::cout << "Expected longest span: 350" << std::endl;
		std::cout << "Actual longest span:   "
				  << sp.longestSpan() << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}


	printHeader("TEST 7: Copy constructor");

	try {
		Span original(5);

		original.addNumber(10);
		original.addNumber(20);
		original.addNumber(40);

		Span copy(original);

		std::cout << "Original longest span: "
				  << original.longestSpan() << std::endl;

		std::cout << "Copied longest span:   "
				  << copy.longestSpan() << std::endl;

		std::cout << "Original shortest span: "
				  << original.shortestSpan() << std::endl;

		std::cout << "Copied shortest span:   "
				  << copy.shortestSpan() << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}


	printHeader("TEST 8: Assignment operator");

	try {
		Span first(5);

		first.addNumber(5);
		first.addNumber(15);
		first.addNumber(50);

		Span second(10);

		second = first;

		std::cout << "First longest span:  "
				  << first.longestSpan() << std::endl;

		std::cout << "Second longest span: "
				  << second.longestSpan() << std::endl;

		std::cout << "First shortest span:  "
				  << first.shortestSpan() << std::endl;

		std::cout << "Second shortest span: "
				  << second.shortestSpan() << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}


	printHeader("TEST 9: 10,000 numbers");

	try {
		const unsigned int count = 10000;

		Span sp(count);
		std::vector<int> values;

		for (unsigned int i = 0; i < count; ++i)
			values.push_back(static_cast<int>(i * 2));

		sp.addNumbers(values.begin(), values.end());

		std::cout << "Inserted " << count
				  << " numbers successfully." << std::endl;

		std::cout << "Expected shortest span: 2" << std::endl;
		std::cout << "Actual shortest span:   "
				  << sp.shortestSpan() << std::endl;

		std::cout << "Expected longest span: 19998" << std::endl;
		std::cout << "Actual longest span:   "
				  << sp.longestSpan() << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}


	printHeader("ALL TESTS FINISHED");

	return 0;
}