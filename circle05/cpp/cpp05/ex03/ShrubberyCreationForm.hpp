#include "Form.hpp"

class ShrubberyCreationForm : public Form {

    private:
        std::string target;

    public:
        ShrubberyCreationForm(std::string name);
        ShrubberyCreationForm(ShrubberyCreationForm const & src);
        ShrubberyCreationForm(const Form &copy);
        ~ShrubberyCreationForm();
        ShrubberyCreationForm &operator=(ShrubberyCreationForm const &rhs);

        void    beSigned(const Bureaucrat &bureaucrat);
        void    execute(Bureaucrat const & target) const;
};

