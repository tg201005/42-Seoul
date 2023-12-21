#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <iostream>
#include <string>
#include <deque>
#include <sstream>
#include <exception>



class RPN {
    private: 

        //canonical form
        RPN(const RPN &copy);
        RPN &operator=(const RPN &copy);

        //database
        std::stack<int> numberStack;

        std::string input;

        //check valid 
        // size of numberStack = size of operatorStack + 1?

        //fillnStack
        void calculateRPN();

            //condition
            bool isNaturalNumber(char c);
            bool isOperator(char c);

    public:
        RPN(std::string input);
        ~RPN();
      
        void execute();

        void printStacks();
        
};
#endif