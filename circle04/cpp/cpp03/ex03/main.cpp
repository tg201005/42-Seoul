#include "DiamondTrap.hpp"

int main(){
    DiamondTrap dt("DiamondTrap");
    dt.attack("target");
    dt.takeDamage(5);
    dt.beRepaired(5);
    dt.guardGate();
    dt.highFivesGuys();
    dt.whoAmI();
    return (0);
}