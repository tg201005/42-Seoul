#include <string.h>
#include <iostream>

class Animal{
    
    protected:
        std::string type;
    
    public:
        Animal();
        Animal(std::string type);
        Animal(Animal const &a);
        virtual ~Animal();

        Animal& operator=(Animal const &a);

        virtual void makeSound() const;
        std::string getType() const;
 
    
};

class Dog : public Animal{
    
    public:
        Dog();
        Dog(Dog const &d);
        ~Dog();

        Dog& operator=(Dog const &d);
        void    makeSound () const;
    
};

class Cat : public Animal{
    
    public:
        Cat();
        Cat(Cat const &c);
        ~Cat();

        Cat& operator=(Cat const &c);

        void    makeSound() const;
    
};
