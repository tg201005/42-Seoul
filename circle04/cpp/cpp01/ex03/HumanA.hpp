#pragma once

#include "Weapon.hpp"
#include <string>

class   HumanA
{
    public:
        HumanA(std::string name, Weapon &weapon);
        ~HumanA();
        void    attack();

    private:
        std::string name;
        Weapon& weapon;
};
