#include "RPN.hpp"
#include <sstream>
#include <iostream>
#include <cctype>
#include <stdexcept>

RPN::RPN() {}

RPN::RPN(const RPN& other) {
	*this = other;
}

RPN& RPN::operator=(const RPN& other) {
	if (this != &other)
		_stack = other._stack;
	return *this;
}

RPN::~RPN() {}

bool RPN::isOperator(const std::string& token) const {
	return (token.length() == 1 
		&& (token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/'));
}

int RPN::evaluate(const std::string& expression) {
	std::istringstream iss(expression);
	std::string token;

#ifdef DEBUG
	std::cout << "Expression: " << expression << std::endl;
#endif

	while (iss >> token) {
#ifdef DEBUG
		std::cout << "\nToken: " << token << std::endl;
#endif

		// If single digit token, push to stack.
		if (token.length() == 1 && std::isdigit(token[0])) {
			_stack.push(token[0] - '0');

#ifdef DEBUG
			std::cout << "  Push: " << token[0] - '0' << std::endl;
			std::cout << "  Stack size: " << _stack.size() << std::endl;
#endif
		}

		// Else if operator token, calculate using top two values.
		else if (isOperator(token)) {
			if (_stack.size() < 2)
				throw std::runtime_error("Error: Cannot operate on single value.");

			int rhs = _stack.top();
			_stack.pop();

			int lhs = _stack.top();
			_stack.pop();

#ifdef DEBUG
			std::cout << "  Pop lhs: " << lhs << std::endl;
			std::cout << "  Pop rhs: " << rhs << std::endl;
#endif

			int result;

			if (token[0] == '+')
				result = lhs + rhs;
			else if (token[0] == '-')
				result = lhs - rhs;
			else if (token[0] == '*')
				result = lhs * rhs;
			else {
				if (rhs == 0)
					throw std::runtime_error("Error: division by zero.");
				result = lhs / rhs;
			}

#ifdef DEBUG
			std::cout << "  Calculate: "
				<< lhs << " " << token[0] << " " << rhs
				<< " = " << result << std::endl;
#endif

			_stack.push(result);

#ifdef DEBUG
			std::cout << "  Push result: " << result << std::endl;
			std::cout << "  Stack size: " << _stack.size() << std::endl;
#endif
		}

		// Any other token is invalid.
		else {
			throw std::runtime_error("Error: invalid token.");
		}
	}
	
	// Only one result should be left.
	if (_stack.size() != 1)
		throw std::runtime_error("Error: invalid expression.");

#ifdef DEBUG
	std::cout << "\nFinal result: " << _stack.top() << std::endl;
#endif

	return _stack.top();
}