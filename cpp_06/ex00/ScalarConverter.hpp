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
    
        static void         convert(const std::string& input);

    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter& other);
        ScalarConverter& operator=(const ScalarConverter& other);
        ~ScalarConverter();

        static InputType    detectInputType(const std::string& input);
        static bool         isChar(const std::string& input);
        static bool         isInt(const std::string& input);
        static bool         isFloat(const std::string& input);
        static bool         isDouble(const std::string& input);
        
        static double       inputToDouble(InputType type, const std::string& input);
        static void         printChar(double value);
		static void			printInt(double value);
};

#endif