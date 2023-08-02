#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include <iostream>
#include <string.h>
// #include "AMateria.hpp"
class AMateria;

class ICharacter
{
    public:
        ICharacter(std::string name);
        ICharacter(ICharacter const &c);
        virtual ~ICharacter() {}
        
        ICharacter& operator=(ICharacter const &c);
        virtual std::string const & getName() const = 0;
        virtual void equip(AMateria* m) = 0;
        virtual void unequip(int idx) = 0;
        virtual void use(int idx, ICharacter& target) = 0;
};

class Character : public ICharacter
{
    private:
        std::string name;
        AMateria* inventory[4];
        int count;
    
    public:
        Character(std::string name);
        virtual ~Character();
        Character(Character const &c);

        Character& operator=(Character const &c);

        std::string const & getName() const;
        void equip(AMateria* m);
        void unequip(int idx);
        void use(int idx, ICharacter& target);
};  

#endif