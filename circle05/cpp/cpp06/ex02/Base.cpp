#include "Base.hpp"

Base::~Base(){
    std::cout << "Base destructor" << std::endl;
}

Base    *Base::generate(void){
    int     random;
    Base    *base;

    srand(time(NULL));
    random = rand() % 3;
    if (random == 0){
        std::cout << "generate A" << std::endl;
        base = new A;
    }
    else if (random == 1){
        std::cout << "generate B" << std::endl;
        base = new B;
    }
    else{
        std::cout << "generate C" << std::endl;
        base = new C;
    }
    return base;
}

void    Base::identify(Base *p){
    if (dynamic_cast<A*>(p)){
        std::cout << "type of pointer is A" << std::endl;
    }
    else if (dynamic_cast<B*>(p)){
        std::cout << "type of pointer is B" << std::endl;
    }
    else if (dynamic_cast<C*>(p)){
        std::cout << "type of pointer is C" << std::endl;
    }
}

void Base::identify(Base &p) {
    try {
        A &a = dynamic_cast<A&>(p);
        std::cout << "type of reference is A" << std::endl;
    } catch(const std::bad_cast&) {
    }

    try {
        B &b = dynamic_cast<B&>(p);
        std::cout << "type of reference is B" << std::endl;
    } catch(const std::bad_cast&) {
    }

    try {
        C &c = dynamic_cast<C&>(p);
        std::cout << "type of reference is C" << std::endl;
    } catch(const std::bad_cast&) {
    }
}

A::~A(){
    std::cout << "A destructor" << std::endl;
}

B::~B(){
    std::cout << "B destructor" << std::endl;
}

C::~C(){
    std::cout << "C destructor" << std::endl;
}