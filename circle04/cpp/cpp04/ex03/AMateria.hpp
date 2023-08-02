#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include <iostream>
#include <string.h>
#include "Character.hpp"

class AMateria
{
    protected:
        std::string type;
    
    public:
        AMateria(std::string const & type);
        ~AMateria();
        AMateria(AMateria const &a);

        AMateria& operator=(AMateria const &a);


        std::string const & getType() const; //Returns the materia type
        
        virtual AMateria* clone() const = 0;
        virtual void use(ICharacter& target);
};

class Ice : public AMateria
{
    public:
        Ice();
        ~Ice();
        Ice(Ice const &a);

        Ice& operator=(Ice const &a);

        AMateria* clone() const;
        void use(ICharacter& target);
};

class Cure : public AMateria
{
    public:
        Cure();
        ~Cure();
        Cure(Cure const &a);

        Cure& operator=(Cure const &a);

        AMateria* clone() const;
        void use(ICharacter& target);
};

#endif