#include <iostream>
#include <string>

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

class ClapTrap{

    protected:
        std::string Name;   
        int hitPoints;
        int energyPoints;
        int attackDamage;

    public:
        ClapTrap(std::string name);
        ClapTrap(const ClapTrap &ct);
        ~ClapTrap();
    
        ClapTrap& operator=(const ClapTrap &ct);

        virtual void attack(std::string const & target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);


        
        bool    isDefeated();
        void    printStatus();

};

#endif