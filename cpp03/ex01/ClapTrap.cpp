#include "ClapTrap.hpp"

bool isDefeated ();

////////////////////////// CONSTRUCTORS //////////////////////////

ClapTrap::ClapTrap(const ClapTrap &ct){
    std::cout << "ClapTrap copy constructor called" << std::endl;
    *this = ct;
    this->Name = ct.Name;
    this->Hit_points = ct.Hit_points;
    this->Energy_points = ct.Energy_points;
    this->Attack_damage = ct.Attack_damage;
}

ClapTrap::ClapTrap(std::string name) : Name(name), Hit_points(10), Energy_points(10), Attack_damage(0){
    std::cout << "ClapTrap string constructor called" << std::endl;
}

ClapTrap::~ClapTrap(){
    std::cout << "ClapTrap destructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &ct){
    std::cout << "ClapTrap assignation operator called" << std::endl;
    if (this != &ct)
    {
        this->Name = ct.Name;
        this->Hit_points = ct.Hit_points;
        this->Energy_points = ct.Energy_points;
        this->Attack_damage = ct.Attack_damage;
    }
    return (*this);
}

////////////////////////// METHODS //////////////////////////

void ClapTrap::attack(std::string const &target){
    if (this->isDefeated())
        return ;
    std::cout << this->Name << " attacks " << target << ", causing " << this->Attack_damage << " points of damage!" << std::endl;
    this->Energy_points--;
}

void ClapTrap::takeDamage(unsigned int amount){
    if (this->isDefeated())
        return ;
    std::cout << this->Name << " takes " << amount << " points of damage!" << std::endl;
    this->Hit_points = this->Hit_points - amount;
}


void ClapTrap::beRepaired(unsigned int amount){
    if (this->isDefeated())
        return ;
    std::cout << this->Name << " is repaired for " << amount << " points of damage!" << std::endl;
    this->Hit_points = this->Hit_points + amount;
    this->Energy_points--;
}

////////////////////////// GETTERS //////////////////////////

std::string ClapTrap::getName(){
    return (this->Name);
}

int ClapTrap::getHit_points(){
    return (this->Hit_points);
}

int ClapTrap::getEnergy_points(){
    return (this->Energy_points);
}

int ClapTrap::getAttack_damage(){
    return (this->Attack_damage);
}

////////////////////////// UTILS //////////////////////////

bool ClapTrap::isDefeated ()
{
    if (this->Hit_points <= 0)
    {
        std::cout << this->Name << " is dead!" << std::endl;
        return (1);
    }
    if (this->Energy_points <= 0)
    {
        std::cout << this->Name << " is out of energy!" << std::endl;
        return (1);
    }
    return (0);

}

void   ClapTrap::print_status(){
    std::cout << this->Name << " has " << this->Hit_points << " hit points and " << this->Energy_points << " energy points." << std::endl;
}