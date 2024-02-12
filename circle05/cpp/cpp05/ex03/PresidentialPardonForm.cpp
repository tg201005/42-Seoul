#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) : Form("PresidentialPardonForm", 25, 5), target(target) {
    return ;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & src) : Form(src) {
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
    Form::beSigned(bureaucrat);
}

void    PresidentialPardonForm::execute(Bureaucrat const & target) const {
    if (this->getGradeSign() < target.getGrade())
        throw Form::GradeTooLowException();
    std::cout << this->target << " has been pardoned by Zafod Beeblebrox" << std::endl;
}

