#include <iostream>
#include <string>
#include "Form.hpp"


class Intern{

    public:
    Intern();
    Intern(Intern const & src);
    ~Intern();

    Intern & operator=(Intern const & rhs);

    Form * makeForm(std::string formName, std::string target);

    class FormNotFoundException : public std::exception{
        virtual const char * what() const throw();
    };

};