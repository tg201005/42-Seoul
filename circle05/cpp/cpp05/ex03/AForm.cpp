#include "AForm.hpp"


AForm::AForm() : name("default"), _signed(false), gradeSign(150), gradeExec(150) {}

AForm::AForm(std::string name, int gradeSign, int gradeExec) : name(name), _signed(false), gradeSign(gradeSign), gradeExec(gradeExec) {
    if (this->gradeSign < 1 || this->gradeExec < 1) {
        throw AForm::GradeTooHighException();
    }
    if (this->gradeSign > 150 || this->gradeExec > 150) {
        throw AForm::GradeTooLowException();
    }
}

AForm::AForm(AForm const& other) : name(other.name), _signed(other._signed), gradeSign(other.gradeSign), gradeExec(other.gradeExec) {}

AForm::~AForm() {}

AForm& AForm::operator=(AForm const& other) {
    if (this != &other) {
        this->_signed = other._signed;
    }
    return *this;
}

std::ostream& operator<<(std::ostream& os,  const AForm& AForm){
    os << "AForm " << AForm.getName() << " is ";
    if (AForm.getSigned()) {
        os << "signed";
    } else {
        os << "not signed";
    }
    os << " and requires grade " << AForm.getGradeSign() << " to sign and grade " << AForm.getGradeExec() << " to execute";
    return os;
}

std::string AForm::getName() const {
    return this->name;
}

bool AForm::getSigned() const {
    return this->_signed;
}

int AForm::getGradeSign() const {
    return this->gradeSign;
}

int AForm::getGradeExec() const {
    return this->gradeExec;
}

void AForm::beSigned(const Bureaucrat & bureaucrat) {
    if (bureaucrat.getGrade() > this->gradeSign) {
        throw AForm::GradeTooLowException();
    }
    this->_signed = true;
}

const char* AForm::GradeTooHighException::what() const throw() {
    return "Grade too high";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "Grade too low";
}



