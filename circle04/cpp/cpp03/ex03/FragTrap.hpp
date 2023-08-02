#include "ClapTrap.hpp"

#ifndef FragTrap_HPP
# define FragTrap_HPP

class FragTrap : virtual public ClapTrap{
    
    public:
        FragTrap(std::string name);
        FragTrap(FragTrap const &ft);
        ~FragTrap(void);

        FragTrap & operator=(FragTrap const &ft);

        void highFivesGuys(void);
};

#endif