#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>

class ScalarConverter {
    public:
    
        enum InputType {
            CHAR,
            INT,
            FLOAT,
            DOUBLE,
            INVALID
        };
    
        static void         convert(const std::string& inpt_str);
        
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter& other);
        ScalarConverter& operator=(const ScalarConverter& other);
        ~ScalarConverter();

        static InputType    detectInputType(const std::string& input);
        static bool         isChar(const std::string& input);
    
        
};

#endif