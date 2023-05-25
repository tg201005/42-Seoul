#include "Harl.hpp"

void    Harl::debug(){
    std::cout << "[ DEBUG ]" << std::endl;
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void    Harl::info(){
    std::cout << "[ INFO ]" << std::endl;
    std::cout << "I cannot believe adding extra bacon costs more money.\nYou didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void    Harl::warning(){
    std::cout << "[ WARNING ]" << std::endl;
    std::cout << "I think I deserve to have some extra bacon for free.\nI’ve been coming here for years and you just started working here last month." << std::endl;
}

void    Harl::error(){
    std::cout << "[ ERROR ]" << std::endl;
    std::cout << "This is unacceptable, I want to speak to the manager now." << std::endl;
}

void    Harl::complain_level(std::string level) {
    Harl harl;

    std::string levels[4] = { "DEBUG", "INFO", "WARNING", "ERROR" };
    void (Harl::*functions[4])() = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };

    int i = 0;
    for (; i < 4; i++) {
        if (levels[i] == level) {
            break;
        }
    }
    switch (i) {
        case 0:
        case 1:
        case 2:
        case 3:
            for (; i < 4; i++)
                (harl.*functions[i])();
            break;
        default:
            std::cout << "Invalid level" << std::endl;
    }
}