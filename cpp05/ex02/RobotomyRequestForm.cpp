#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45) {
    return ;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), target(target) {
    return ;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & src) : AForm(src) {
    return ;
}

RobotomyRequestForm::~RobotomyRequestForm() {
    return ;
}

RobotomyRequestForm & RobotomyRequestForm::operator=(RobotomyRequestForm const & rhs) {
    if (this != &rhs)
    {
        this->target = rhs.target;
    }
    return *this;
}

void    RobotomyRequestForm::beSigned(Bureaucrat const & bureaucrat) {
    AForm::beSigned(bureaucrat);
}

void    RobotomyRequestForm::execute(Bureaucrat const & target) const {
    if (this->getGradeSign() < target.getGrade())
        throw AForm::GradeTooLowException();
    std::cout << "* drillin noises *" << std::endl;
    srand(time(NULL));
    if (rand() % 2 == 0)
        std::cout << this->target << " has been robotomized successfully" << std::endl;
    else
        std::cout << this->target << " has failed to be robotomized" << std::endl;
}