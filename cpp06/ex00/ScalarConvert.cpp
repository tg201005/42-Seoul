#include "ScalarConvert.hpp"
#include <iomanip>
#include <cmath>
#include <limits>
#include <exception>

// type check

bool ScalarConverter::isCharLiteral(const std::string& literal) {
    return (literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'');
}

bool ScalarConverter::isIntLiteral(const std::string& literal) {
    std::stringstream ss(literal);
    int i;
    ss >> i;

    return !ss.fail() && ss.eof();
}

bool ScalarConverter::isDoubleLiteral(const std::string& literal) {
    if (literal == "nan" || literal == "+inf" || literal == "inff" || literal == "-inf") {
        return true;
    }
    std::stringstream ss(literal);
    double d;
    ss >> d;

    return !ss.fail() && ss.eof();
}

bool ScalarConverter::isFloatLiteral(const std::string& literal) {
    if (literal == "nanf" || literal == "+inff" || literal == "inff" || literal == "-inff") {
        return true;
    }

    std::stringstream ss;

    if (literal.back() == 'f') {
        ss << literal.substr(0, literal.length() - 1);
    } 
    else {
        ss << literal;
    }

    float f;
    ss >> f;

    return !ss.fail() && ss.eof();
}

// print type

void    ScalarConverter::printChar(double &value){
    std::cout << "char: ";
    if (std::isnan(value) || std::isinf(value)){
        std::cout << "impossible" << std::endl;
    }else if (value < std::numeric_limits<char>::min() || value > std::numeric_limits<char>::max()){
        std::cout << "impossible" << std::endl;
    }else if (!isprint(static_cast<char>(value))) {
        std::cout << "Non displayable" << std::endl;
    } else {
        std::cout << '\'' << static_cast<char>(value) << '\'' << std::endl; 
    }
}

void    ScalarConverter::printInt(double &value){
    if (std::isnan(value) || std::isinf(value))
        std::cout << "int: impossible" << std::endl;
    else if (value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max())
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(value) << std::endl;
}

void    ScalarConverter::printFloat(double &value){
    if (std::isnan(value) || std::isinf(value))
        std::cout << "float: " << value << "f" << std::endl;
    else if (value < std::numeric_limits<float>::min() || value > std::numeric_limits<float>::max())
        std::cout << "float: impossible" << std::endl;
    else
        std::cout << "float: "<< std::fixed << std::setprecision(1) << static_cast<float>(value) << "f" << std::endl;
}

void    ScalarConverter::printDouble(double &value){
    if (std::isnan(value) || std::isinf(value))
        std::cout << "double: " << value << std::endl;
    else if (value < std::numeric_limits<double>::min() || value > std::numeric_limits<double>::max())
        std::cout << "double: impossible" << std::endl;
    else
        std::cout << "double: "<< std::fixed << std::setprecision(1) << value << std::endl;
}

// value getter

double  ScalarConverter::getValue(const std::string& literal) {

    // // for test
    // std::cout << isCharLiteral(literal) << std::endl;
    // std::cout << isIntLiteral(literal) << std::endl;
    // std::cout << isFloatLiteral(literal) << std::endl;
    // std::cout << isDoubleLiteral(literal) << std::endl;

    // std::cout << "char cast" << static_cast<double>(literal[1]) << std::endl;
    // std::cout << "int cast" << static_cast<double>(std::stoi(literal)) << std::endl;
    // std::cout << "float cast" << static_cast<double>(std::stof(literal)) << std::endl;
    // std::cout << "double cast" << std::stod(literal) << std::endl;


    if (isCharLiteral(literal)) {
        return static_cast<double>(literal[1]);
    }
    else if (isIntLiteral(literal)) {
        std::stringstream ss(literal);
        int i;
        ss >> i;
        return static_cast<double>(i);
    }
    else if (isFloatLiteral(literal)) {
        std::stringstream ss(literal.substr(0, literal.length() - 1));
        float f;
        ss >> f;
        return static_cast<double>(f);
    }
    else if (isDoubleLiteral(literal)) {
        std::stringstream ss(literal);
        double d;
        ss >> d;
        return d;
    }
    else {
        throw std::invalid_argument("Invalid format");
    }
}

// convert 

void    ScalarConverter::convert(const std::string& literal) {

    double  value;

    try {
        value = getValue(literal);
    } catch (...) {
        std::cout << "Invalid format" << std::endl;
        return ;
    }
    
    printChar(value);
    printInt(value);
    printFloat(value);
    printDouble(value);
}

// canonical form

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& other) {
    *this = other;
}

ScalarConverter::~ScalarConverter() {}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
    if (this != &other) {
        *this = other;
    }
    return *this;
}