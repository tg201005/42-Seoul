#include "HumanA.hpp"


HumanA::HumanA(std::string name, Weapon &weapon) : weapon(weapon)
{
    this->name = name;
}

//by setting constructor arg, we can force the user to set the name and weapon

HumanA::~HumanA()
{
    std::cout << this->name << " is dead" << std::endl;
}

void    HumanA::attack()
{
    std::cout << this->name << " attacks with his " << this->weapon.getType() << std::endl;
}