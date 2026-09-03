#include "Span.hpp"
#include <stdexcept>
#include <algorithm>

Span::Span() : _maxSize(0) {}

Span::Span(unsigned int N) : _maxSize(N) {}

Span::Span(const Span& other) : _maxSize(other._maxSize), _numbers(other._numbers) {}

Span& Span::operator=(const Span& other) {
	if (this != &other) {
		_maxSize = other._maxSize;
		_numbers = other._numbers;
	}

	return *this;
}

Span::~Span() {}

void Span::addNumber(int number) {
	if (_numbers.size() >= _maxSize)
		throw std::runtime_error("Span is full.");
	
	_numbers.push_back(number);
}

unsigned int Span::longestSpan() {
	if (_numbers.size() < 2)
		throw std::runtime_error("Not enough numbers in span.");

	int min = *std::min_element(_numbers.begin(), _numbers.end());
	int max = *std::max_element(_numbers.begin(), _numbers.end());

	return (max - min);
}

// Sort
// Compare neighboring values
// Return the smallest difference
unsigned int Span::shortestSpan() {
	if (_numbers.size() < 2)
		throw std::runtime_error("Not enough numbers in span.");
	
	std::vector<int> sorted = _numbers;

	std::sort(sorted.begin(), sorted.end());

	unsigned int shortest = sorted[1] - sorted[0];

	for (unsigned int i = 1; i < sorted.size() - 1; i++) {
		unsigned int span = sorted[i + 1] - sorted[i];
		if (span < shortest)
			shortest = span;
	}

	return shortest;
}

