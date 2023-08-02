#pragma once

#include <iostream>
#include <string>

class   Weapon
{
    public:
        Weapon(std::string type);
        ~Weapon();
        const std::string&  getType();
        void                setType(std::string type);
    
    private:
        std::string type;
};