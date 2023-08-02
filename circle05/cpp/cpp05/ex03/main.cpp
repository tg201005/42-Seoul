#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main() 
{
    std::cout << "-----Robotomy-----" << std::endl;
    
    {
        Bureaucrat b1("king", 1);
        Bureaucrat b2("slave", 150);
        Intern someRandomIntern;
        Form* rrf;
        rrf = someRandomIntern.makeForm("robotomy request", "Bender");
        b1.executeForm(*rrf);    
        b2.executeForm(*rrf);
    }

    std::cout << "-----Presidential-----" << std::endl;

    {
        Bureaucrat b1("king", 1);
        Bureaucrat b2("slave", 150);
        Intern someRandomIntern;
        Form* rrf;
        rrf = someRandomIntern.makeForm("presidential pardon", "Bender");
        b1.executeForm(*rrf);
        b2.executeForm(*rrf);
    }



    std::cout << "-----Shrubbery-----" << std::endl;

   {
        Bureaucrat b1("king", 1);
        Bureaucrat b2("slave", 150);
        Intern someRandomIntern;
        Form* rrf;
        rrf = someRandomIntern.makeForm("shrubbery creation", "Bender");
        b1.executeForm(*rrf);
        b2.executeForm(*rrf);
    }

    std::cout << "-----Unknown-----" << std::endl;

    {
        Bureaucrat b1("king", 1);
        Bureaucrat b2("slave", 150);
        Intern someRandomIntern;
        Form* rrf;
        rrf = someRandomIntern.makeForm("unknown", "Bender");
    }

}