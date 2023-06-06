#include "Character.hpp"

//ICARACTER

ICharacter::ICharacter(std::string name)
{
    this->name = name;
}

ICharacter::~ICharacter()
{
}

ICharacter::ICharacter(ICharacter const &c)
{
    *this = c;
}

ICharacter& ICharacter::operator=(ICharacter const &c)
{
    this->name = c.name;
    return (*this);
}

//CHARACTER

Character::Character(std::string name) : ICharacter(name)
{
    this->count = 0;
    for (int i = 0; i < 4; i++)
        this->inventory[i] = NULL;
}

Character::~Character()
{
    for (int i = 0; i < this->count; i++)
        delete this->inventory[i];
}

Character::Character(Character const &c) : ICharacter(c)
{
    *this = c;
}

Character& Character::operator=(Character const &c)
{
    this->name = c.name;
    this->count = c.count;
    for (int i = 0; i < this->count; i++)
        this->inventory[i] = c.inventory[i]->clone();
    return (*this);
}

std::string const & Character::getName() const
{
    return (this->name);
}

void Character::equip(AMateria* m)
{
    if (this->count < 4)
    {
        this->inventory[this->count] = m;
        this->count++;
    }
}

void Character::unequip(int idx)
{
    if (idx >= 0 && idx < this->count)
    {
        for (int i = idx; i < this->count - 1; i++)
            this->inventory[i] = this->inventory[i + 1];
        this->inventory[this->count - 1] = NULL;
        this->count--;
    }
}

void Character::use(int idx, ICharacter& target)
{
    if (idx >= 0 && idx < this->count)
        this->inventory[idx]->use(target);
}