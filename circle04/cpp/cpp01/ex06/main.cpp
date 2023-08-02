#include "Harl.hpp"

int main(int ac, char **av){
    Harl    harl;
    
    if (ac != 2) {
        std::cout << "Invalid Arg Num" << std::endl;
        return (1);
    }    

    harl.complain_level(av[1]);
    
    return (0);
}