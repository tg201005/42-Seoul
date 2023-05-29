#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(){
    ScavTrap st("ScavTrap");

    st.attack("target");
    st.takeDamage(10);
    st.print_status();
    st.beRepaired(10);
    st.print_status();
    st.guardGate();
    st.print_status();

    st.takeDamage(100);
    st.guardGate();
    return (0);
}