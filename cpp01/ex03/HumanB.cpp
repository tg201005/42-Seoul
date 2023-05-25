#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
    this->name = name;
    std::cout << this->name << " is born" << std::endl;
}

HumanB::~HumanB()
{
    std::cout << this->name << " is dead" << std::endl;
}

void    HumanB::setWeapon(Weapon &weapon)
{
    this->weapon = &weapon;
}

//reference is used when the object is inserted into the function

void    HumanB::attack()
{
    std::cout << this->name << " attacks with there " << this->weapon->getType() << std::endl;
}

