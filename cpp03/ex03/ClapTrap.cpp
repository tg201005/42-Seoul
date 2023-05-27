#include "ClapTrap.hpp"

int isDefeated (ClapTrap* ct);

////////////////////////// CONSTRUCTORS //////////////////////////

ClapTrap::ClapTrap(const ClapTrap &ct){
    std::cout << "ClapTrap copy constructor called" << std::endl;
    *this = ct;
    this->Name = ct.Name;
    this->Hitpoints = ct.Hitpoints;
    this->Energy_points = ct.Energy_points;
    this->Attack_damage = ct.Attack_damage;
}

ClapTrap::ClapTrap(std::string name) : Name(name), Hitpoints(10), Energy_points(10), Attack_damage(0){
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
        this->Hitpoints = ct.Hitpoints;
        this->Energy_points = ct.Energy_points;
        this->Attack_damage = ct.Attack_damage;
    }
    return (*this);
}

////////////////////////// METHODS //////////////////////////

void ClapTrap::attack(std::string const &target){
    if (isDefeated(this))
        return ;
    std::cout << "ClapTrap " << this->Name << " attacks " << target << ", causing " << this->Attack_damage << " points of damage!" << std::endl;
    this->Energy_points--;
}

void ClapTrap::takeDamage(unsigned int amount){
    std::cout << "ClapTrap " << this->Name << " takes " << amount << " points of damage!" << std::endl;
    this->Hitpoints = this->Hitpoints - amount;
}

void ClapTrap::beRepaired(unsigned int amount){
    if (isDefeated(this))
        return ;
    std::cout << "ClapTrap " << this->Name << " is repaired for " << amount << " points of damage!" << std::endl;
    this->Hitpoints = this->Hitpoints + amount;
    this->Energy_points--;
}

////////////////////////// GETTERS //////////////////////////

std::string ClapTrap::getName(){
    return (this->Name);
}

int ClapTrap::getHitpoints(){
    return (this->Hitpoints);
}

int ClapTrap::getEnergy_points(){
    return (this->Energy_points);
}

int ClapTrap::getAttack_damage(){
    return (this->Attack_damage);
}

////////////////////////// UTILS //////////////////////////

bool ClapTrap::isDefeated (ClapTrap* ct)
{
    if (ct->Hitpoints <= 0)
    {
        std::cout << "ClapTrap " << ct->Name << " is dead!" << std::endl;
        return (1);
    }
    if (ct->Energy_points <= 0)
    {
        std::cout << "ClapTrap " << ct->Name << " is out of energy!" << std::endl;
        return (1);
    }
    return (0);

}
