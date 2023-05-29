#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name){
    this->Name = name;
    this->hitPoints = FragTrap::hitPoints;
    this->energyPoints = ScavTrap::energyPoints;
    this->attackDamage = FragTrap::attackDamage;
    std::cout << "DiamondTrap " << this->Name << " is born!" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &dt) : ClapTrap(dt.Name + "_clap_name"), ScavTrap(dt.Name), FragTrap(dt.Name){
    this->Name = dt.Name;
    this->hitPoints = FragTrap::hitPoints;
    this->energyPoints = ScavTrap::energyPoints;
    this->attackDamage = FragTrap::attackDamage;
    std::cout << "DiamondTrap " << this->Name << " is born!" << std::endl;
}

DiamondTrap::~DiamondTrap(){
    std::cout << "DiamondTrap " << this->Name << " is dead!" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &dt){
    this->Name = dt.Name;
    this->hitPoints = FragTrap::hitPoints;
    this->energyPoints = ScavTrap::energyPoints;
    this->attackDamage = FragTrap::attackDamage;
    return (*this);
}

void DiamondTrap::whoAmI(){
    std::cout << "DiamondTrap " << this->Name << " is " << this->ClapTrap::Name << std::endl;
}

