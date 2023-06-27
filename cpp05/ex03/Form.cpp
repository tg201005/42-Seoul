#include "Form.hpp"


Form::Form() : name("default"), _signed(false), gradeSign(150), gradeExec(150) {}

Form::Form(std::string name, int gradeSign, int gradeExec) : name(name), _signed(false), gradeSign(gradeSign), gradeExec(gradeExec) {
    if (this->gradeSign < 1 || this->gradeExec < 1) {
        throw Form::GradeTooHighException();
    }
    if (this->gradeSign > 150 || this->gradeExec > 150) {
        throw Form::GradeTooLowException();
    }
}

Form::Form(Form const& other) : name(other.name), _signed(other._signed), gradeSign(other.gradeSign), gradeExec(other.gradeExec) {}

Form::~Form() {}

Form& Form::operator=(Form const& other) {
    if (this != &other) {
        this->_signed = other._signed;
    }
    return *this;
}

std::ostream& operator<<(std::ostream& os,  const Form& Form){
    os << "Form " << Form.getName() << " is ";
    if (Form.getSigned()) {
        os << "signed";
    } else {
        os << "not signed";
    }
    os << " and requires grade " << Form.getGradeSign() << " to sign and grade " << Form.getGradeExec() << " to execute";
    return os;
}

std::string Form::getName() const {
    return this->name;
}

bool Form::getSigned() const {
    return this->_signed;
}

int Form::getGradeSign() const {
    return this->gradeSign;
}

int Form::getGradeExec() const {
    return this->gradeExec;
}

void Form::beSigned(const Bureaucrat & bureaucrat) {
    if (bureaucrat.getGrade() > this->gradeSign) {
        throw Form::GradeTooLowException();
    }
    this->_signed = true;
}

const char* Form::GradeTooHighException::what() const throw() {
    return "Grade too high";
}

const char* Form::GradeTooLowException::what() const throw() {
    return "Grade too low";
}



