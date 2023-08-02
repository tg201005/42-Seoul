#include "MateriaSource.hpp"

// IMATERIASOURCE

IMateriaSource::IMateriaSource()
{
}

IMateriaSource::~IMateriaSource()
{
}

IMateriaSource::IMateriaSource(IMateriaSource const &m)
{
    *this = m;
}

IMateriaSource& IMateriaSource::operator=(IMateriaSource const &m)
{
    (void)m;
    return (*this);
}

// MATERIASOURCE

MateriaSource::MateriaSource()
{
    this->count = 0;
    for (int i = 0; i < 4; i++)
        this->inventory[i] = NULL;
}

MateriaSource::~MateriaSource()
{
    for (int i = 0; i < this->count; i++)
        delete this->inventory[i];
}

MateriaSource::MateriaSource(MateriaSource const &m)
{
    *this = m;
}

MateriaSource& MateriaSource::operator=(MateriaSource const &m)
{
    this->count = m.count;
    for (int i = 0; i < this->count; i++)
        this->inventory[i] = m.inventory[i]->clone();
    return (*this);
}

void MateriaSource::learnMateria(AMateria* m)
{
    if (this->count < 4)
    {
        this->inventory[this->count] = m;
        this->count++;
    }
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    for (int i = 0; i < this->count; i++)
    {
        if (this->inventory[i]->getType() == type)
            return (this->inventory[i]->clone());
    }
    return (NULL);
}


