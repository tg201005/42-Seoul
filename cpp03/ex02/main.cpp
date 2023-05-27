#include "FragTrap.hpp"

//write main code using class ClapTrap and FragTrap

int main(){
    FragTrap ft("FragTrap");
    FragTrap ft2(ft);
    FragTrap ft3("FragTrap3");
    ft3 = ft2;
    ft.attack("target");
    ft.takeDamage(10);
    ft.beRepaired(10);
    ft.highFivesGuys();
    return (0);
}