# include "Zombie.hpp"

void    Zombie::announce()
{
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void    Zombie::set_name(std::string name)
{
    this->name = name;
}

Zombie::Zombie () 
{
    this->name = "default";
}

Zombie::~Zombie () 
{
    std::cout << this->name << ": I'm dying..." << std::endl;
}