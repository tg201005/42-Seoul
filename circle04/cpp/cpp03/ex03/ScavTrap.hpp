#include "ClapTrap.hpp"

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP


class ScavTrap : virtual public ClapTrap{
    
    public:
        ScavTrap(std::string name);
        ScavTrap(ScavTrap const &st);
        ~ScavTrap(void);

        ScavTrap & operator=(ScavTrap const & rhs);

        void guardGate();
};

#endif
