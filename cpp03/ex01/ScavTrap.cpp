#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name){
    std::cout << "ScavTrap name constructor called" << std::endl;
    this->Hitpoints = 100;
    this->Energy_points = 50;
    this->Attack_damage = 20;  
}

ScavTrap::ScavTrap(const ScavTrap &st) : ClapTrap(st){
    std::cout << "ScavTrap copy constructor called" << std::endl;
    this->Hitpoints = st.Hitpoints;
    this->Energy_points = st.Energy_points;
    this->Attack_damage = st.Attack_damage;
}

ScavTrap::~ScavTrap(){
    std::cout << "ScavTrap destructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &st){
    std::cout << "ScavTrap assignation operator called" << std::endl;
    this->Name = st.Name;
    this->Hitpoints = st.Hitpoints;
    this->Energy_points = st.Energy_points;
    this->Attack_damage = st.Attack_damage;
    return (*this);
}

void ScavTrap::guardGate(){
    std::cout << "ScavTrap have enterred in Gate keeper mode" << std::endl;
}
