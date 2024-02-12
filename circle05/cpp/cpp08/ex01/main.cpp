#include "Span.hpp"
#include <iostream>
#include <unistd.h>



int main(){
    try {
        Span sp = Span(5);
        sp.addNumber(5);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
}

// int main (){
//     try {
//         Span sp = Span(5);
//         sp.addNumber(5);
//         sp.addNumber(3);
//         sp.addNumber(17);
//         sp.addNumber(9);
//         sp.addNumber(11);
//         std::cout << sp.shortestSpan() << std::endl;
//         std::cout << sp.longestSpan() << std::endl;
//         sp.addNumber(11, 20);
//     } catch (const std::exception& e) {
//         std::cerr << e.what() << std::endl;
//     }
// }