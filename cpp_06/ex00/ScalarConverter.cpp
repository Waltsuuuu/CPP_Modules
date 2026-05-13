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
void ScalarConverter::convert(const std::string& inpt_str) {
    std::cout << "Input: " << inpt_str << std::endl;

    InputType type = detectInputType(inpt_str);

    std::cout << "Type: " << type << std::endl;
}

// Detect input type (CHAR, INT, FLOAT, DOUBLE, INVALID)
ScalarConverter::InputType ScalarConverter::detectInputType(const std::string& input) {
    if (isChar(input))
        return ScalarConverter::CHAR;
    if (isInt(input))
        return ScalarConverter::INT;
    if (isFloat(input))
        return ScalarConverter::FLOAT;
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