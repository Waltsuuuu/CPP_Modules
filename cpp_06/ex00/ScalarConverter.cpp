#include "ScalarConverter.hpp"
#include <iostream>
#include <cctype> // isdigit, isprint

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
    std::cout << "Input: " << input << std::endl;

    InputType type = detectInputType(input);
    std::cout << "Type: " << type << std::endl;

    double value = 0;
    if (type == CHAR)
        value = static_cast<double>(input[0]);
    else if (type == INT)
        value = std::atoi(input.c_str());
    else if (type == FLOAT)
        value = std::atof(input.c_str());
    else if (type == DOUBLE)
        value = std::atof(input.c_str());
    else {
        std::cout << "Invalid input" << std::endl;
        return ;
    }
    std::cout << "Value: " << value << std::endl;
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