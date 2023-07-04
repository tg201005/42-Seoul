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
    static void convertChar(const std::string& literal);
    static bool isIntLiteral(const std::string& literal);
    static void convertInt(const std::string& literal);
    static bool isFloatLiteral(const std::string& literal);
    static void convertFloat(const std::string& literal);
    static bool isDoubleLiteral(const std::string& literal);
    static void convertDouble(const std::string& literal);
};
