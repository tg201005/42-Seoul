#include "FragTrap.hpp"

//write main code using class ClapTrap and FragTrap

int main(){
    FragTrap ft("FragTrap");
    
    ft.attack("target");
    ft.takeDamage(10);
    ft.printStatus();
    ft.beRepaired(10);
    ft.printStatus();
    ft.highFivesGuys();
    
    ft.takeDamage(100);
    ft.printStatus();
    ft.highFivesGuys();
    return (0);
}