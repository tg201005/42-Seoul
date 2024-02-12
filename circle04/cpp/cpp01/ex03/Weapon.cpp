#include "Weapon.hpp"

Weapon::Weapon(std::string type) : type(type)
{
    std::cout << this->type << ": Weapon born!" << std::endl;
}

Weapon::~Weapon()
{
    std::cout << this->type << ": Weapon dying..." << std::endl;
}

const std::string&  Weapon::getType()
{
    return (this->type);
}

void    Weapon::setType(std::string type)
{
    this->type = type;
}
