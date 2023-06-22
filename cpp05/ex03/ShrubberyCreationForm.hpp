#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {

    private:
        std::string _target;

    public:
        ShrubberyCreationForm(std::string name);
        ShrubberyCreationForm(ShrubberyCreationForm const & src);
        ShrubberyCreationForm(const AForm &copy);
        ~ShrubberyCreationForm();
        ShrubberyCreationForm &operator=(ShrubberyCreationForm const &rhs);

        void    beSigned(const Bureaucrat &bureaucrat);
        void    execute(Bureaucrat const & target) const;
};

