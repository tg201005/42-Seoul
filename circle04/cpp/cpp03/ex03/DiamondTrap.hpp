#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap{
    private:
        std::string Name;
    public:
        DiamondTrap(std::string name);
        DiamondTrap(const DiamondTrap &dt);
        ~DiamondTrap();
        DiamondTrap &operator=(const DiamondTrap &dt);
        void whoAmI();

};