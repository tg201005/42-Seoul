#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main() {
    //write the code using Form class
    //write the code using Bureaucrat class
    //write the code using try/catch

   Bureaucrat b1("king", 1);
    Bureaucrat b2("slave", 150);

    std::cout << b1 << std::endl;
    std::cout << b2 << std::endl;
    
    std::cout << "------" << std::endl;
    
    ShrubberyCreationForm f3("shrubbery");

    b1.executeForm(f3);    
    b2.executeForm(f3);
    std::cout << "------" << std::endl;

    PresidentialPardonForm f1("president");
    
    b1.executeForm(f1);
    b2.executeForm(f1);
    std::cout << "------" << std::endl;
    
    RobotomyRequestForm f2("robotomy");

    b1.executeForm(f2);
    b2.executeForm(f2);
    std::cout << "------" << std::endl;
    
}