#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {

    private:
        std::string target;

    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(std::string target);
        ShrubberyCreationForm(ShrubberyCreationForm const & src);
        ~ShrubberyCreationForm();
        ShrubberyCreationForm &operator=(ShrubberyCreationForm const &rhs);

        void    beSigned(const Bureaucrat &bureaucrat);
        void    execute(Bureaucrat const & target) const;
};

