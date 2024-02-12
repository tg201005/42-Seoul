#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), target("default") {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), target(name) {}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & src) : AForm(src) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(ShrubberyCreationForm const & rhs) {
    if (this != &rhs)
    {
        this->target = rhs.target;
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
    std::string filename = target.getName() + "_shrubbery";
    std::cout << target.getName() << std::endl;
    std::cout << filename << std::endl;
    std::cout << filename.c_str() << std::endl;
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