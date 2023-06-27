
#include "Form.hpp"

class PresidentialPardonForm : public Form
{
    private:
        std::string target;
    public:
        PresidentialPardonForm(std::string target);
        PresidentialPardonForm(PresidentialPardonForm const & src);
        ~PresidentialPardonForm();
        PresidentialPardonForm & operator=(PresidentialPardonForm const & rhs);
        
        void    beSigned(Bureaucrat const & bureaucrat);
        void    execute(Bureaucrat const & executor) const;

};

