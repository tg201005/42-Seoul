#include <iostream>
#include "iter.hpp"

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    std::cout << "-------------------" << std::endl;
    std::cout << "int array:" << std::endl;
    iter(arr, 5, print<int>);

    std::cout << "-------------------" << std::endl;
    std::cout << "char array:" << std::endl;
    char str[] = "Hello";
    iter(str, 5, print<char>);

    std::cout << "-------------------" << std::endl;
    std::cout << "float array:" << std::endl;
    float farr[] = {1.1f, 2.2f, 3.3f, 4.4f, 5.5f};
    iter(farr, 5, print<float>);



    return 0;
}
