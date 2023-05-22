#pragma once

#include "Weapon.hpp"
#include <string>

class HumanB
{
    public:
        HumanB(std::string name);
        ~HumanB();
        void    setWeapon(Weapon &weapon);
        void    attack();
    
    private:
        std::string name;
        Weapon* weapon;
};

