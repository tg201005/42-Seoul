#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name){
    std::cout << "FragTrap name constructor called" << std::endl;
    this->Hitpoints = 100;
    this->Energy_points = 100;
    this->Attack_damage = 30;  
}

FragTrap::FragTrap(const FragTrap &ft) : ClapTrap(ft){
    std::cout << "FragTrap copy constructor called" << std::endl;
    this->Hitpoints = ft.Hitpoints;
    this->Energy_points = ft.Energy_points;
    this->Attack_damage = ft.Attack_damage;
}

FragTrap::~FragTrap(){
    std::cout << "FragTrap destructor called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap &ft){
    std::cout << "FragTrap assignation operator called" << std::endl;
    this->Name = ft.Name;
    this->Hitpoints = ft.Hitpoints;
    this->Energy_points = ft.Energy_points;
    this->Attack_damage = ft.Attack_damage;
    return (*this);
}

void FragTrap::highFivesGuys(){
    std::cout << "FragTrap have enterred in high five mode" << std::endl;
}