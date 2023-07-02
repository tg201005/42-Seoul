#include <iostream>
#include <sstream>
#include <limits>

class ScalarConverter {
public:
    static void convert(const std::string& literal) {

        std::cout << literal << std::endl;
        // Detect the type of the literal
        if (isCharLiteral(literal)) {
            convertChar(literal);
        } else if (isIntLiteral(literal)) {
            convertInt(literal);
        } else if (isFloatLiteral(literal)) {
            convertFloat(literal);
        } else if (isDoubleLiteral(literal)) {
            convertDouble(literal);
        } else {
            std::cout << "Invalid literal format." << std::endl;
        }
    }
    
private:
    static bool isCharLiteral(const std::string& literal) {
        return (literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'');
    }
    
    static void convertChar(const std::string& literal) {
        if (isprint(literal[1])) {
            char c = literal[1];
            std::cout << "char: " << c << std::endl;
            std::cout << "int: " << static_cast<int>(c) << std::endl;
            std::cout << "float: " << static_cast<float>(c) << std::endl;
            std::cout << "double: " << static_cast<double>(c) << std::endl;
        } else {
            std::cout << "char: Non displayable" << std::endl;
            std::cout << "int: impossible" << std::endl;
            std::cout << "float: impossible" << std::endl;
            std::cout << "double: impossible" << std::endl;
        }
    }
    
    static bool isIntLiteral(const std::string& literal) {
        std::stringstream ss(literal);
        int i;
        ss >> i;
        return !ss.fail() && ss.eof();
    }
    
    static void convertInt(const std::string& literal) {
        std::stringstream ss(literal);
        int i;
        ss >> i;
        if (!ss.fail() && ss.eof()) {
            std::cout << "char: ";
            if (isprint(static_cast<char>(i))) {
                std::cout << static_cast<char>(i) << std::endl;
            } else {
                std::cout << "Non displayable" << std::endl;
            }
            std::cout << "int: " << i << std::endl;
            std::cout << "float: " << static_cast<float>(i) << "f" << std::endl;
            std::cout << "double: " << static_cast<double>(i) << std::endl;
        } else {
            std::cout << "Invalid int literal." << std::endl;
        }
    }
    
    static bool isFloatLiteral(const std::string& literal) {
        std::stringstream ss(literal);
        float f;
        ss >> f;
        return !ss.fail() && ss.eof();
    }
    
    static void convertFloat(const std::string& literal) {
        std::stringstream ss(literal);
        float f;
        ss >> f;
        if (!ss.fail() && ss.eof()) {
            std::cout << "char: ";
            if (isprint(static_cast<char>(f))) {
                std::cout << static_cast<char>(f) << std::endl;
            } else {
                std::cout << "Non displayable" << std::endl;
            }
            std::cout << "int: " << static_cast<int>(f) << std::endl;
            std::cout << "float: " << f << "f" << std::endl;
            std::cout << "double: " << static_cast<double>(f) << std::endl;
        } else {
            std::cout << "Invalid float literal." << std::endl;
        }
    }
    
    static bool isDoubleLiteral(const std::string& literal) {
        std::stringstream ss(literal);
        double d;
        ss >> d;
        return !ss.fail() && ss.eof();
    }
    
    static void convertDouble(const std::string& literal) {
        std::stringstream ss(literal);
        double d;
        ss >> d;
        if (!ss.fail() && ss.eof()) {
            std::cout << "char: ";
            if (isprint(static_cast<char>(d))) {
                std::cout << static_cast<char>(d) << std::endl;
            } else {
                std::cout << "Non displayable" << std::endl;
            }
            std::cout << "int: " << static_cast<int>(d) << std::endl;
            std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
            std::cout << "double: " << d << std::endl;
        } else {
            std::cout << "Invalid double literal." << std::endl;
        }
    }
};

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cout << "Usage: " << argv[0] << " <literal>" << std::endl;
        return 1;
    }
    
    ScalarConverter::convert(argv[1]);
    
    return 0;
}
