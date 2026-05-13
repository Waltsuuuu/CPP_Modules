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