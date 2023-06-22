#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target) {
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
        this->_target = rhs._target;
    }
    return *this;
}

void    RobotomyRequestForm::beSigned(Bureaucrat const & bureaucrat) {
    AForm::beSigned(bureaucrat);
}

void    RobotomyRequestForm::execute(Bureaucrat const & target) const {
    if (this->getGradeSign() < target.getGrade())
        throw AForm::GradeTooLowException();
    std::cout << "* drilling noises *" << std::endl;
    if (rand() % 2 == 0)
        std::cout << this->_target << " has been robotomized successfully" << std::endl;
    else
        std::cout << this->_target << " has failed to be robotomized" << std::endl;
}