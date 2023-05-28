#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name){
    this->Name = name;
    this->Hitpoints = FragTrap::Hitpoints;
    this->Energy_points = ScavTrap::Energy_points;
    this->Attack_damage = FragTrap::Attack_damage;
    std::cout << "DiamondTrap " << this->Name << " is born!" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &dt) : ClapTrap(dt.Name + "_clap_name"), ScavTrap(dt.Name), FragTrap(dt.Name){
    this->Name = dt.Name;
    this->Hitpoints = FragTrap::Hitpoints;
    this->Energy_points = ScavTrap::Energy_points;
    this->Attack_damage = FragTrap::Attack_damage;
    std::cout << "DiamondTrap " << this->Name << " is born!" << std::endl;
}

DiamondTrap::~DiamondTrap(){
    std::cout << "DiamondTrap " << this->Name << " is dead!" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &dt){
    this->Name = dt.Name;
    this->Hitpoints = FragTrap::Hitpoints;
    this->Energy_points = ScavTrap::Energy_points;
    this->Attack_damage = FragTrap::Attack_damage;
    return (*this);
}

void DiamondTrap::whoAmI(){
    std::cout << "DiamondTrap " << this->Name << " is " << this->ClapTrap::Name << std::endl;
}

