#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"
#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
    private:
        std::string target;
    public:
        RobotomyRequestForm();
        RobotomyRequestForm(std::string target);
        RobotomyRequestForm(RobotomyRequestForm const & src);
        ~RobotomyRequestForm();
        RobotomyRequestForm & operator=(RobotomyRequestForm const & rhs);
        
        void    beSigned(Bureaucrat const & bureaucrat);
        void    execute(Bureaucrat const & executor) const;

};

#endif