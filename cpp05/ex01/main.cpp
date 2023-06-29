#include "Bureaucrat.hpp"

int main() {

   Bureaucrat King("King", 1);
    Bureaucrat Slave("Slave", 150);

    std::cout << King << std::endl;
    std::cout << Slave << std::endl;

    Form f1("f1", 1, 1);
    Form f2("f2", 150, 150);

    std::cout << f1 << std::endl;
    std::cout << f2 << std::endl;

    King.signForm(f1);
    King.signForm(f2);
    Slave.signForm(f1);    
    Slave.signForm(f2);
}