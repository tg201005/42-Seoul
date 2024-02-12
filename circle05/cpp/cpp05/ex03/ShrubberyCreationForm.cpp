#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>


ShrubberyCreationForm::ShrubberyCreationForm(std::string name) : Form("ShrubberyCreationForm", 145, 137), target(name) {}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & src) : Form(src) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(const Form &copy) : Form(copy) {}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(ShrubberyCreationForm const & rhs) {
    if (this != &rhs)
    {
        this->target = rhs.target;
    }
    return *this;
}

void    ShrubberyCreationForm::beSigned(Bureaucrat const & bureaucrat){
    if (bureaucrat.getGrade() > this->getGradeSign())
        throw Form::GradeTooLowException();
    else
        this->_signed = true;
}

void    ShrubberyCreationForm::execute(Bureaucrat const &target) const{

    if (target.getGrade() > this->getGradeExec())
        throw Form::GradeTooLowException();
    
    std::ofstream file;
    std::string filename = this->target + "_shrubbery";
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