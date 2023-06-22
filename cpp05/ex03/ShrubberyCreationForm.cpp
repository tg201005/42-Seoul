#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>


ShrubberyCreationForm::ShrubberyCreationForm(std::string name) : AForm("ShrubberyCreationForm", 145, 137), _target(name) {}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & src) : AForm(src) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(const AForm &copy) : AForm(copy) {}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(ShrubberyCreationForm const & rhs) {
    if (this != &rhs)
    {
        this->_target = rhs._target;
    }
    return *this;
}

void    ShrubberyCreationForm::beSigned(Bureaucrat const & bureaucrat){
    if (bureaucrat.getGrade() > this->getGradeSign())
        throw AForm::GradeTooLowException();
    else
        this->_signed = true;
}

void    ShrubberyCreationForm::execute(Bureaucrat const &target) const{

    if (target.getGrade() > this->getGradeExec())
        throw AForm::GradeTooLowException();
    
    std::ofstream file;
    std::string filename = this->_target + "_shrubbery";
    file.open(filename.c_str());
        if (!file.is_open())
            throw std::runtime_error("Error opening file");
    file << "      _-_\n"
                 "    /~~   ~~\\\n"
                 "/~~         ~~\\\n"
                 "{               }\n"
                 " \\  _-     -_  /\n"
                 "   ~  \\\\ //  ~\n"
                 "_- -   | | _- _\n"
                 "  _ -  | |   -_\n"
                 "      // \\\\\n" << std::endl;
    file.close();
}