#include "Bureaucrat.hpp"

int main() {
    //write the code using Form class
    //write the code using Bureaucrat class
    //write the code using try/catch

   Bureaucrat b1("b1", 1);
    Bureaucrat b2("b2", 150);

    std::cout << b1 << std::endl;
    std::cout << b2 << std::endl;

    Form f1("f1", 1, 1);
    Form f2("f2", 150, 150);

    std::cout << f1 << std::endl;
    std::cout << f2 << std::endl;

    b1.signForm(f1);
    b1.signForm(f2);
    b2.signForm(f1);    
    b2.signForm(f2);
}