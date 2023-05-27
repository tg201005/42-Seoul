#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name){
    std::cout << "DiamondTrap name constructor called" << std::endl;
    this->Name = name;
    this->Hitpoints = 100;
    this->Energy_points = 50;
    this->Attack_damage = 30;  
}