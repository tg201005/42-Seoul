#ifndef AForm_HPP
#define AForm_HPP

#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"


class Bureaucrat;

class AForm{
    protected:
        const std::string name;
        bool _signed;
        const int gradeSign;
        const int gradeExec;

    public:
        AForm();
        AForm(std::string name, int gradeSign, int gradeExec);
        AForm(const AForm &copy);
        ~AForm();
        AForm &operator=(const AForm &op);

        std::string getName() const;
        bool getSigned() const;
        int getGradeSign() const;
        int getGradeExec() const;
        
        virtual void beSigned(const Bureaucrat &bureaucrat) = 0;
        virtual void execute(Bureaucrat const &target) const = 0;


        class GradeTooHighException: public std::exception{
            public:
                virtual const char* what() const throw();
        };
        
        class GradeTooLowException: public std::exception{
            public:
                virtual const char* what() const throw();
        };
};

std::ostream& operator<<(std::ostream& os, AForm const& AForm);

#endif