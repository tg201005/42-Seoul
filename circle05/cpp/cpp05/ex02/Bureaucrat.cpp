#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("default"), grade(150) {}

Bureaucrat::Bureaucrat(std::string const& name, int grade) : name(name), grade(grade) {
    if (this->grade < 1) {
        throw Bureaucrat::GradeTooHighException();
    }
    if (this->grade > 150) {
        throw Bureaucrat::GradeTooLowException();
    }
}

Bureaucrat::Bureaucrat(Bureaucrat const& other) : name(other.name), grade(other.grade){}

Bureaucrat::~Bureaucrat() {}

Bureaucrat& Bureaucrat::operator=(Bureaucrat const& other) {
    if (this != &other) {
        this->grade = other.grade;
    }
    return *this;
}

std::ostream& operator<<(std::ostream& os, Bureaucrat const& bureaucrat){
    os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
    return os;

}

std::string const& Bureaucrat::getName() const {
    return this->name;
}

int Bureaucrat::getGrade() const {
    return this->grade;
}

void Bureaucrat::incrementGrade() {
    if (this->grade - 1 < 1) {
        throw Bureaucrat::GradeTooHighException();
    }
    this->grade--;
}

void Bureaucrat::decrementGrade() {
    if (this->grade + 1 > 150) {
        throw Bureaucrat::GradeTooLowException();
    }
    this->grade++;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade too low";
}

void    Bureaucrat::signForm(AForm& f) const {
    try {
        f.beSigned(*this);
        std::cout << this->getName() << " signed " << f.getName() << std::endl;
    }
    catch (std::exception &e) {
        std::cout << this->getName() << " couldn't sign " << f.getName() << " because " << e.what() << std::endl;
    }
}

void    Bureaucrat::executeForm(const AForm &f) const {
    try {
        f.execute(*this);
        std::cout << this->getName() << " executed " << f.getName() << std::endl;
    }
    catch (std::exception &e) {
        std::cout << this->getName() << " couldn't execute " << f.getName() << " because " << e.what() << std::endl;
    }
}


