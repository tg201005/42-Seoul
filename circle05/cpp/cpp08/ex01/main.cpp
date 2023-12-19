#include "Span.hpp"
#include <iostream>
#include <unistd.h>



int main(){
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
    return 0;
}

//

// int main() {
//     Span sp = Span(10001);

//     srand(time(NULL));

//     for (int i = 0; i < 10000; i++) {
//         sp.addNumber(rand() % 10000);
//     }

//     sp.print();

//     try {
//         std::cout << sp.shortestSpan() << std::endl;
//         std::cout << sp.longestSpan() << std::endl;
//     } catch (const std::exception& e) {
//         std::cerr << e.what() << std::endl;
//     }
//     return 0;
// }

// add number 1~5000

//------------------test case 1------------------

// int main() {
//     Span sp = Span(5000);

//     sp.addNumber(1, 5000);

//     try {
//         std::cout << sp.shortestSpan() << std::endl;
//         std::cout << sp.longestSpan() << std::endl;
//     } catch (const std::exception& e) {
//         std::cerr << e.what() << std::endl;
//     }
//     return 0;
// }

