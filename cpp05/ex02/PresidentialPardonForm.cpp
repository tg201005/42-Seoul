#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), target("default") {
    return ;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), target(target) {
    return ;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & src) : AForm(src) {
    return ;
}

PresidentialPardonForm::~PresidentialPardonForm() {
    return ;
}

PresidentialPardonForm & PresidentialPardonForm::operator=(PresidentialPardonForm const & rhs) {
    if (this != &rhs)
    {
        this->target = rhs.target;
    }
    return *this;
}

void    PresidentialPardonForm::beSigned(Bureaucrat const & bureaucrat) {
    AForm::beSigned(bureaucrat);
}

void    PresidentialPardonForm::execute(Bureaucrat const & target) const {
    if (this->getGradeSign() < target.getGrade())
        throw AForm::GradeTooLowException();
    std::cout << this->target << " has been pardoned by Zafod Beeblebrox" << std::endl;
}

