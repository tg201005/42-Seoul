#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include "AMateria.hpp"


class IMateriaSource
{
    public:
        IMateriaSource();
        IMateriaSource(IMateriaSource const &m);
        IMateriaSource& operator=(IMateriaSource const &m);

        virtual ~IMateriaSource() {}
        virtual void learnMateria(AMateria*) = 0;
        virtual AMateria* createMateria(std::string const & type) = 0;
};

class MateriaSource : public IMateriaSource
{
    private:
        AMateria* inventory[4];
        int count;
    
    public:
        MateriaSource();
        virtual ~MateriaSource();
        MateriaSource(MateriaSource const &m);

        MateriaSource& operator=(MateriaSource const &m);

        void learnMateria(AMateria* m);
        AMateria* createMateria(std::string const & type);
};

#endif
