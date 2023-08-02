#include <string.h>
#include <iostream>

class WrongAnimal{
    
    protected:
        std::string type;
    
    public:
        WrongAnimal();
        WrongAnimal(std::string type);
        WrongAnimal(WrongAnimal const &a);
        ~WrongAnimal();

        WrongAnimal& operator=(WrongAnimal const &a);

        void    makeSound() const;
        std::string getType() const;
    
};

class WrongCat : public WrongAnimal{
    
    public:
        WrongCat();
        WrongCat(WrongCat const &c);
        ~WrongCat();

        WrongCat& operator=(WrongCat const &c);

        void    makeSound() const;
    
};
