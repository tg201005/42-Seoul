#include "Span.hpp"
#include <iostream>

int main() {
    Span sp = Span(10001);

    // // input 5 numbers into sp
    // sp.addNumber(5);
    // sp.addNumber(3);
    // sp.addNumber(17);
    // sp.addNumber(9);
    // sp.addNumber(11);


    //input 10000 random numbers into sp=
    srand(time(NULL));
    for (int i = 0; i < 10000; i++) {
        sp.addNumber(rand() % 1000000);
    }



    // print shortest and longest span 

    try {
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
