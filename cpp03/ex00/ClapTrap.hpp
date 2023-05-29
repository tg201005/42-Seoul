#include <iostream>
#include <string>

class ClapTrap{

    private:
        std::string Name;   
        int Hit_points;
        int Energy_points;
        int Attack_damage;

    public:
        ClapTrap(std::string name);
        ClapTrap(const ClapTrap &ct);
        ~ClapTrap();
    
        ClapTrap& operator=(const ClapTrap &ct);

        void attack(std::string const & target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);

        std::string getName();
        int getHit_points();
        int getEnergy_points();
        int getAttack_damage();
        
        bool isDefeated();

};