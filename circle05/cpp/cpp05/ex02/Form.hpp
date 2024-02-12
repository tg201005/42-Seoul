#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form{
    private:
        const std::string name;
        bool _signed;
        const int gradeSign;
        const int gradeExec;

    public:
        Form();
        Form(std::string name, int gradeSign, int gradeExec);
        Form(const Form &copy);
        ~Form();
        Form &operator=(const Form &op);

        std::string getName() const;
        bool getSigned() const;
        int getGradeSign() const;
        int getGradeExec() const;
        
        void beSigned(const Bureaucrat &bureaucrat);


        class GradeTooHighException: public std::exception{
            public:
                virtual const char* what() const throw();
        };
        
        class GradeTooLowException: public std::exception{
            public:
                virtual const char* what() const throw();
        };
};

std::ostream& operator<<(std::ostream& os, Form const& form);

#endif