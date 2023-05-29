#include "ClapTrap.hpp"

bool isDefeated ();
void printStatus();

////////////////////////// CONSTRUCTORS //////////////////////////

ClapTrap::ClapTrap(const ClapTrap &ct){
    std::cout << "ClapTrap copy constructor called" << std::endl;
    *this = ct;
    this->Name = ct.Name;
    this->hitPoints = ct.hitPoints;
    this->energyPoints = ct.energyPoints;
    this->attackDamage = ct.attackDamage;
}

ClapTrap::ClapTrap(std::string name) : Name(name), hitPoints(10), energyPoints(10), attackDamage(0){
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
        this->hitPoints = ct.hitPoints;
        this->energyPoints = ct.energyPoints;
        this->attackDamage = ct.attackDamage;
    }
    return (*this);
}

////////////////////////// METHODS //////////////////////////

void ClapTrap::attack(std::string const &target){
    if (this->isDefeated())
        return ;
    std::cout << this->Name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
    this->energyPoints--;
}

void ClapTrap::takeDamage(unsigned int amount){
    if (this->isDefeated())
        return ;
    std::cout << this->Name << " takes " << amount << " points of damage!" << std::endl;
    this->hitPoints = this->hitPoints - amount;
}

void ClapTrap::beRepaired(unsigned int amount){
    if (this->isDefeated())
        return ;
    std::cout << this->Name << " is repaired for " << amount << " points of damage!" << std::endl;
    this->hitPoints = this->hitPoints + amount;
    this->energyPoints--;
}


////////////////////////// UTILS //////////////////////////

bool ClapTrap::isDefeated ()
{
    if (this->hitPoints <= 0)
    {
        std::cout << this->Name << " is dead!" << std::endl;
        return (1);
    }
    if (this->energyPoints <= 0)
    {
        std::cout << this->Name << " is out of energy!" << std::endl;
        return (1);
    }
    return (0);

}

void   ClapTrap::print_status(){
    std::cout << this->Name << " has " << this->hitPoints << " hit points and " << this->energyPoints << " energy points." << std::endl;
}