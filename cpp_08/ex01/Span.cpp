#include "Span.hpp"
#include <stdexcept>

Span::Span() : _maxSize(0) {}

Span::Span(unsigned int N) : _maxSize(N) {}

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

