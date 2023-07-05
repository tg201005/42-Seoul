#pragma once

#include <string>
#include <sstream>
#include <iostream>
#include <limits>
#include <cctype>
#include <iomanip>

class ScalarConverter {

public:
    static void convert(const std::string& literal);
 
    
private:
    static bool isCharLiteral(const std::string& literal);
    static bool isIntLiteral(const std::string& literal);
    static bool isDoubleLiteral(const std::string& literal);
    static bool isFloatLiteral(const std::string& literal);

    static void printChar(double &value);
    static void printInt(double &value);
    static void printFloat(double &value);
    static void printDouble(double &value);

    static double  getValue(const std::string& literal);

    ScalarConverter();
    ~ScalarConverter();
    ScalarConverter(const ScalarConverter& other);
    ScalarConverter& operator=(const ScalarConverter& other);
};
