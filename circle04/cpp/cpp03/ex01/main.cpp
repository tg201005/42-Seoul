#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(){
    ScavTrap st("ScavTrap");

    st.attack("target");
    st.takeDamage(10);
    st.printStatus();
    st.beRepaired(10);
    st.printStatus();
    st.guardGate();
    st.printStatus();

    st.takeDamage(100);
    st.guardGate();
    return (0);
}