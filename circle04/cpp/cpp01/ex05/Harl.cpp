#include "Harl.hpp"

void    Harl::debug(){
    std::cout << "Debug" << std::endl;
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void    Harl::info(){
    std::cout << "Info" << std::endl;
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void    Harl::warning(){
    std::cout << "Warning" << std::endl;
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming here for years and you just started working here last month." << std::endl;
}

void    Harl::error(){
    std::cout << "Error" << std::endl;
    std::cout << "This is unacceptable, I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level) {
    std::string levels[4] = { "debug", "info", "warning", "error" };
    void (Harl::*functions[4])() = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };

    for (int i = 0; i < 4; i++) {
        if (levels[i] == level) {
            (this->*functions[i])();
            return;
        }
    }

    std::cout << "Invalid level" << std::endl;
}

// int main() {
//     // 함수 포인터 선언
//     int (*operation)(int, int);

//     // 덧셈 함수를 가리키는 함수 포인터
//     operation = add;
//     int result = operation(5, 3);
//     std::cout << "덧셈 결과: " << result << std::endl;

//     // 뺄셈 함수를 가리키는 함수 포인터
//     operation = subtract;
//     result = operation(5, 3);
//     std::cout << "뺄셈 결과: " << result << std::endl;

//     return 0;
// }