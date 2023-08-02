#include "AMateria.hpp"

// AMateria

AMateria::AMateria(std::string const &type)
{
    this->type = type;
}

AMateria::~AMateria()
{
}

AMateria::AMateria(AMateria const &a)
{
    *this = a;
}

AMateria& AMateria::operator=(AMateria const &a)
{
    this->type = a.type;
    return (*this);
}

std::string const & AMateria::getType() const
{
    return (this->type);
}

void    AMateria::use(ICharacter& target)
{
    (void)target;
}

// Ice

Ice::Ice() : AMateria("ice")
{
}

Ice::~Ice()
{
}

Ice::Ice(Ice const &a) : AMateria(a)
{
}

Ice& Ice::operator=(Ice const &a)
{
    *this = a;
    return (*this);
}

void    Ice::use(ICharacter& target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

AMateria*   Ice::clone() const
{
    return (new Ice(*this));
}


// Cure


Cure::Cure() : AMateria("cure")
{
}

Cure::~Cure()
{
}

Cure::Cure(Cure const &a) : AMateria(a)
{
}

Cure& Cure::operator=(Cure const &a)
{
    *this = a;
    return (*this);
}

void    Cure::use(ICharacter& target)
{
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

AMateria*   Cure::clone() const
{
    return (new Cure(*this));
}