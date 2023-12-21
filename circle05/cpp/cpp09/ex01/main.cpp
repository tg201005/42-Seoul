#include "RPN.hpp"

int main(int ac, char **av){

    //check av
    // make RPN
    // execute

    if (ac != 2)
    {
        std::cout << "Wrong number of arguments" << std::endl;
        return 1;
    }

    //char * to std::string
    std::string input(av[1]);
    RPN rpn(input);
    rpn.execute();
}