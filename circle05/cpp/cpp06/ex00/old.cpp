#include "ScalarConvert.hpp"
#include <iomanip>
   

void ScalarConverter::convert(const std::string& literal) {

        // // can check if literal is char, int, float, double        
        // std::cout << isCharLiteral(literal) << std::endl;
        // std::cout << isIntLiteral(literal) << std::endl;
        // std::cout << isFloatLiteral(literal) << std::endl;
        // std::cout << isDoubleLiteral(literal) << std::endl;

        if (isCharLiteral(literal)) {
            convertChar(literal);
        } else if (isIntLiteral(literal)) {
            convertInt(literal);
        } else if (isDoubleLiteral(literal)) {
            convertDouble(literal);
        } else if (isFloatLiteral(literal)) {
            convertFloat(literal);
        } else {
            std::cout << "Invalid literal format." << std::endl;
        }
    }



bool ScalarConverter::isCharLiteral(const std::string& literal) {
    return (literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'');
}

void ScalarConverter::convertChar(const std::string& literal) {
    if (isprint(literal[1])) {
        char c = literal[1];
        std::cout << "char: " << '\'' <<  c << '\'' <<  std::endl;
        std::cout << "int: " << static_cast<int>(c) << std::endl;
        std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(c) << 'f' << std::endl;
        std::cout << "double: "<< std::fixed << std::setprecision(1)  << static_cast<double>(c) << std::endl;
    } else {
        std::cout << "char: Non displayable" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
    }
}
    
    bool ScalarConverter::isIntLiteral(const std::string& literal) {
        std::stringstream ss(literal);
        int i;
        ss >> i;
        return !ss.fail() && ss.eof();
    }
    
    void ScalarConverter::convertInt(const std::string& literal) {
        std::stringstream ss(literal);
        int i;
        ss >> i;
        std::cout << "char: ";
        if (isprint(static_cast<char>(i))) {
            std::cout << '\'' << static_cast<char>(i) << '\'' << std::endl;
        } else {
            std::cout << "Non displayable" << std::endl;
        }
        std::cout << "int: " << i << std::endl;
        std::cout << std::fixed << std::setprecision(1)  << "float: " << static_cast<float>(i) << "f" << std::endl;
        std::cout << std::fixed << std::setprecision(1) << "double: " << static_cast<double>(i) << std::endl;
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
    
    void ScalarConverter::convertDouble(const std::string& literal) {
        
        if (literal == "nan" || literal == "+inf" || literal == "inf" || literal == "-inf") {
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            std::cout << "float: " << literal << "f" << std::endl;
            std::cout << "double: " << literal << std::endl;
            return;
        }

        std::stringstream ss(literal);
        double d;
        ss >> d;
        std::cout << "char: ";
        if (isprint(static_cast<char>(d))) {
            std::cout << '\'' << static_cast<char>(d) << '\'' << std::endl;
        } else {
            std::cout << "Non displayable" << std::endl;
        }
        std::cout << "int: " << static_cast<int>(d) << std::endl;
        std::cout << "float: "<< std::fixed << std::setprecision(1) << static_cast<float>(d) << "f" << std::endl;
        std::cout << "double: "<< std::fixed << std::setprecision(1) << d << std::endl;
    }

    bool ScalarConverter::isFloatLiteral(const std::string& literal) {
        if (literal == "nanf" || literal == "+inff" || literal == "inff" || literal == "-inff") {
            return true;
        }
        std::stringstream ss(literal.substr(0, literal.length() - 1));
        float f;
        ss >> f;

        return !ss.fail() && ss.eof();
    }
    
    void ScalarConverter::convertFloat(const std::string& literal) {
        
        if (literal == "nanf" || literal == "+inff" || literal == "inff" || literal == "-inff") {
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            std::cout << "float: " << literal << std::endl;
            std::cout << "double: " << literal.substr(0, literal.length() - 1) << std::endl;
            return;
        }

        std::stringstream ss(literal.substr(0, literal.length() - 1));
        float f;
        ss >> f;
        std::cout << "char: ";
        if (isprint(static_cast<char>(f))) {
            std::cout << '\'' << static_cast<char>(f) << '\'' << std::endl;
        } else {
            std::cout << "Non displayable" << std::endl;
        }
        std::cout << "int: " << static_cast<int>(f) << std::endl;
        std::cout << "float: " << std::fixed << std::setprecision(1) << f  <<"f" << std::endl;
        std::cout << "double: "<< std::fixed << std::setprecision(1)  << static_cast<double>(f) << std::endl;
    }
