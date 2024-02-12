#ifndef BASE_HPP
# define BASE_HPP

# include <iostream>
# include <string>
# include <sstream>
# include <cstdlib>


class Base{

    public:
        virtual ~Base();
        Base    *generate(void);
        void    identify(Base *p);
        void    identify(Base &p);
};

class A : public Base{
    public:
        virtual ~A();
};

class B : public Base{
    public:
        virtual ~B();
};

class C : public Base{
    public:
        virtual ~C();
};


#endif