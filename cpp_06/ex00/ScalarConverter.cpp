#include "ScalarConverter.hpp"
#include <iostream>

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

void ScalarConverter::convert(const std::string& inpt_str) {
    std::cout << "Input: " << inpt_str << std::endl;
}