#include "ScalarConverter.hpp"
#include <iostream>
#include <cctype> // isdigit, isprint
#include <limits> // int_min, int_max
#include <iomanip> // setprecision 

ScalarConverter::ScalarConverter(){
}

ScalarConverter::ScalarConverter(const ScalarConverter& other){
    (void)other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other){
    (void)other;
    return (*this);
}

ScalarConverter::~ScalarConverter(){
}

// Converter 
void ScalarConverter::convert(const std::string& input) {

    InputType type = detectInputType(input);
    if (type == INVALID){
        std::cout << "Invalid input" << std::endl;
        return ;
    }

    double value = inputToDouble(type, input);

    printChar(value);
	printInt(value);
	printFloat(value);
	printDouble(value);
}

double ScalarConverter::inputToDouble(InputType type, const std::string& input) {
    if (type == CHAR)
        return (static_cast<double>(input[0]));
    if (type == INT)
        return (std::atof(input.c_str()));
    if (type == FLOAT)
        return (std::atof(input.c_str()));
    if (type == DOUBLE)
         return (std::atof(input.c_str()));
    return 0;
}

// Detect input type (CHAR, INT, FLOAT, DOUBLE, INVALID)
ScalarConverter::InputType ScalarConverter::detectInputType(const std::string& input) {
    if (isChar(input))
        return ScalarConverter::CHAR;
    if (isInt(input))
        return ScalarConverter::INT;
    if (isFloat(input))
        return ScalarConverter::FLOAT;
    if (isDouble(input))
        return ScalarConverter::DOUBLE;
    else
        return ScalarConverter::INVALID;
}

// Single printable non-digit character
bool ScalarConverter::isChar(const std::string& input) {
    if (input.length() != 1)
        return false;
    if (std::isdigit(input[0]))
        return false;
    if (!std::isprint(input[0]))
        return false;
    return true;
}

// Integer rules:
// - May start with '+' or '-'
// - Remaining characters must all be digits
// - Cannot be empty
// - Cannot contain '.', 'f', or letters
bool ScalarConverter::isInt(const std::string& input) {
    if (input.empty())
        return false;
    
    size_t i = 0;

    if (input[i] == '+' || input[i] == '-')
        i++;
    
    if (i == input.length())
        return false;

    while (i < input.length()){
        if (!std::isdigit(input[i]))
            return false;
        i++;
    }

    return true;
}

// Float rules:
// - Accepts pseudo-literals: nanf, +inff, -inff
// - May start with '+' or '-'
// - Must end with 'f'
// - Must contain exactly one '.'
// - Must have digits around the '.'
// - Everything else must be digits
bool ScalarConverter::isFloat(const std::string& input) {
    if (input == "nanf" || input == "+inff" || input == "-inff")
        return true;

    if (input.empty())
        return false;

    if (input[input.length() - 1] != 'f')
        return false;

    size_t  i = 0;
    bool    hasDot = false;
    bool    hasDigitBeforeDot = false;
    bool    hasDigitAfterDot = false;

    if (input[i] == '+' || input[i] == '-')
        i++;

    while (i < input.length() - 1) {
        if (input[i] == '.') {
            if (hasDot)
                return false;
            hasDot = true;
        }
        else if(std::isdigit(input[i])) {
            if (!hasDot)
                hasDigitBeforeDot = true;
            else
                hasDigitAfterDot = true;
        }
        else
            return false;
        i++;
    }

    return hasDot && hasDigitBeforeDot && hasDigitAfterDot;
}

// Double rules:
// - Accepts pseudo-literals: nan, +inf, -inf
// - May start with '+' or '-'
// - Must contain exactly one '.'
// - Must have digits around the '.'
// - Must not end with 'f'
// - Everything else must be digits
bool ScalarConverter::isDouble(const std::string& input) {
    if (input == "nan" || input == "+inf" || input == "-inf")
        return true;
    
    if (input.empty())
        return false;

    size_t  i = 0;
    bool    hasDot = false;
    bool    hasDigitBeforeDot = false;
    bool    hasDigitAfterDot = false;

    if (input[i] == '+' || input[i] == '-')
        i++;

    if (i == input.length())
        return false;

    while (i < input.length()) {
        if (input[i] == '.') {
            if (hasDot)
                return false;
            hasDot = true;
        }
        else if(std::isdigit(input[i])) {
            if (!hasDot)
                hasDigitBeforeDot = true;
            else
                hasDigitAfterDot = true;
        }
        else
            return false;
        i++;
    }

    return hasDot && hasDigitBeforeDot && hasDigitAfterDot;
}

// Print functions
void ScalarConverter::printChar(double value) {
    // nan check (every value = itself, except nan)
    if (value != value) {
        std::cout << "char: impossible" << std::endl;
        return ;
    }

    // ASCII range check
    if (value < 0 || value > 127) {
        std::cout << "char: impossible" << std::endl;
        return ;
    }

    char c = static_cast<char>(value);
    
    // Non-printable check
    if (!std::isprint(c)) {
        std::cout << "char: Non displayable" << std::endl;
        return ;
    }

    std::cout << "char: '" << c << "'" << std::endl;
}

void ScalarConverter::printInt(double value) {
	if (value != value) {
		std::cout << "int: impossible" << std::endl;
        return ;
	}

	if (value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max()) {
		std::cout << "int: impossible" << std::endl;
		return ;
	}

	int int_val = static_cast<int>(value);

	std::cout << "int: " << int_val << std::endl;
}

void ScalarConverter::printFloat(double value) {
	if (value != value) {
		std::cout << "float: nanf" << std::endl;
		return ;
	}

	float float_val = static_cast<float>(value);

	if (float_val == std::numeric_limits<float>::infinity()) {
		std::cout << "float: +inff" << std::endl;
		return ;
	}
	if (float_val == -std::numeric_limits<float>::infinity()) {
		std::cout << "float: -inff" << std::endl;
		return ;
	}

	// Whole number check
	if (float_val == static_cast<int>(float_val))
		std::cout << std::fixed << std::setprecision(1);
	
	std::cout << "float: " << float_val << "f" << std::endl;
}

void ScalarConverter::printDouble(double value) {
	if (value != value) {
		std::cout << "double: nan" << std::endl;
		return ;
	}

	if (value == std::numeric_limits<double>::infinity()) {
		std::cout << "double: +inf" << std::endl;
		return ;
	}
	if (value == -std::numeric_limits<double>::infinity()) {
		std::cout << "double: -inf" << std::endl;
		return ;
	}

	// Whole number check
	if (value == static_cast<int>(value))
		std::cout << std::fixed << std::setprecision(1);
	
	std::cout << "double: " << value << std::endl;
}
