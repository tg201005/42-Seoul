#include "RPN.hpp"

//canonical form
RPN::RPN(std::string input)
{
    this->input = input;
}

RPN::~RPN()
{
}

RPN::RPN(const RPN &copy)
{
    *this = copy;
}

RPN &RPN::operator=(const RPN &copy)
{
    if (this != &copy)
    {
        this->input = copy.input;
        this->numberStack = copy.numberStack;
    }
    return *this;
}

//check condition
bool RPN::isNaturalNumber(char c)
{
    return c >= '0' && c <= '9';
}

bool RPN::isOperator(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/';
}

void RPN::calculateRPN()
{
    int a, b, result;
    char temp;


    std::stringstream ss(input);

    while (ss >> temp)
    {
        if (isNaturalNumber(temp))
        { 
            a = temp - '0';
            numberStack.push(a);

        }
        else if (isOperator(temp))
        {
            if (numberStack.size() < 2)
                throw std::runtime_error("Error: invalid input, size");

            b = numberStack.top();
            numberStack.pop();
            a = numberStack.top();
            numberStack.pop();

            switch (temp)
            {
                case '+':
                    result = a + b;
                    break;
                case '-':
                    result = a - b;
                    break;
                case '*':
                    result = a * b;
                    break;
                case '/':
                    if (b == 0)
                        throw std::runtime_error("Error: division by zero");
                    result = a / b;
                    break;
            }
            numberStack.push(result);
        }
        else
            throw std::runtime_error("Error: invalid input, char");
    }
    if (numberStack.size() != 1)
        throw std::runtime_error("Error: invalid input");

    std::cout << numberStack.top() << std::endl;
}

void RPN::execute()
{
    try {
        calculateRPN();
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}