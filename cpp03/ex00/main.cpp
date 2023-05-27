#include "ClapTrap.hpp"

int main(){
    ClapTrap a("a");
    ClapTrap b("b");
    ClapTrap c("c");
    
    a.attack("b");
    b.takeDamage(2);
    b.beRepaired(1);
    b.attack("c");
    c.takeDamage(2);
    c.beRepaired(1);
    c.attack("a");
    a.takeDamage(2);


}