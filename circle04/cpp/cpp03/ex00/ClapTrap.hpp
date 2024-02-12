#include <iostream>
#include <string>

class ClapTrap{

    private:
        std::string Name;   
        int hitPoints;
        int energyPoints;
        int attackDamage;

    public:
        ClapTrap(std::string name);
        ClapTrap(const ClapTrap &ct);
        ~ClapTrap();
    
        ClapTrap& operator=(const ClapTrap &ct);

        void attack(std::string const & target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);


        
        bool isDefeated();
        void printStatus();

};