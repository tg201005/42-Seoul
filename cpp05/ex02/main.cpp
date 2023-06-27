#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main() {


   Bureaucrat b1("king", 1);
    Bureaucrat b2("slave", 150);

    std::cout << b1 << std::endl;
    std::cout << b2 << std::endl;
    
    std::cout << "------" << std::endl;
    
    ShrubberyCreationForm f3("shrubbery");
    std::cout << f3 << std::endl;

    b1.executeForm(f3);    
    b2.executeForm(f3);
    std::cout << "------" << std::endl;

    PresidentialPardonForm f1("president");
    std::cout << f1 << std::endl;

    b1.executeForm(f1);
    b2.executeForm(f1);
    std::cout << "------" << std::endl;
    
    RobotomyRequestForm f2("robotomy");
    std::cout << f2 << std::endl;

    b1.executeForm(f2);
    b2.executeForm(f2);
    std::cout << "------" << std::endl;
    
}