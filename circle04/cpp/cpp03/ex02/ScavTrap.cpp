#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name){
    std::cout << "ScavTrap name constructor called" << std::endl;
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 20;  
}

ScavTrap::ScavTrap(const ScavTrap &st) : ClapTrap(st){
    std::cout << "ScavTrap copy constructor called" << std::endl;
    this->hitPoints = st.hitPoints;
    this->energyPoints = st.energyPoints;
    this->attackDamage = st.attackDamage;
}

ScavTrap::~ScavTrap(){
    std::cout << "ScavTrap destructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &st){
    std::cout << "ScavTrap assignation operator called" << std::endl;
    this->Name = st.Name;
    this->hitPoints = st.hitPoints;
    this->energyPoints = st.energyPoints;
    this->attackDamage = st.attackDamage;
    return (*this);
}

void ScavTrap::guardGate(){
    if (this->isDefeated())
        return ;
    std::cout << "ScavTrap have enterred in Gate keeper mode" << std::endl;
}
