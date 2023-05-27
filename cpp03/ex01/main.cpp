#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(){
    ClapTrap ct("ClapTrap");
    ScavTrap st("ScavTrap");

    ct.attack("target");
    ct.takeDamage(10);
    ct.beRepaired(10);

    st.attack("target");
    st.takeDamage(10);
    st.beRepaired(10);
    st.guardGate();

    return (0);
}