#include "Base.hpp"

int main(){
    Base   base;
    Base  *base_ptr;

    base_ptr = base.generate();
    
    base.identify(base_ptr);
    base.identify(*base_ptr);
    delete base_ptr;

}