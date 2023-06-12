#include "Bureaucrat.hpp"

int main() {
    try {
        Bureaucrat bureaucrat("John Doe", 100);
        std::cout << bureaucrat << std::endl;

        bureaucrat.incrementGrade();
        std::cout << bureaucrat << std::endl;

        bureaucrat.decrementGrade();
        std::cout << bureaucrat << std::endl;

        bureaucrat.decrementGrade();  // Throws GradeTooHighException
    }
    catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}