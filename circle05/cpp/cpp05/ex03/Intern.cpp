#include "Intern.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern() {}

Intern::Intern(Intern const& src) {
    *this = src;
}

Intern::~Intern() {}

Intern& Intern::operator=(Intern const& rhs) {
    if (this != &rhs) {}
    return *this;
}

Form* Intern::makeForm(std::string formName, std::string target) {
    Form* form = NULL;
    try {
        if (formName == "robotomy request") {
            form = new RobotomyRequestForm(target);
        } else if (formName == "presidential pardon") {
            form = new PresidentialPardonForm(target);
        } else if (formName == "shrubbery creation") {
            form = new ShrubberyCreationForm(target);
        } else {
            throw Intern::FormNotFoundException();
        }
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    return form;

}

const char* Intern::FormNotFoundException::what() const throw() {
   return "Form not found";
}
