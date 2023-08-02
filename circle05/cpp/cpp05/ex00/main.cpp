#include "Bureaucrat.hpp"

int main() {
    try {
        Bureaucrat b1("Middle", 100);
        std::cout << b1 << std::endl;

        b1.incrementGrade();
        std::cout << b1 << std::endl;

        b1.decrementGrade();
        std::cout << b1 << std::endl;

        std::cout << "-----" << std::endl;

       Bureaucrat b2("King", 1);
       std::cout << b2 << std::endl;
       
       b2.incrementGrade();
       std::cout << b2 << std::endl;

       std::cout << "-----" << std::endl;

       Bureaucrat b3("Slave", 150);
       b3.decrementGrade();
        std::cout << b3 << std::endl;




    }
    catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

  try {
       std::cout << "-----" << std::endl;

       Bureaucrat b3("Slave", 150);
       std::cout << b3 << std::endl;

        b3.decrementGrade();
        std::cout << b3 << std::endl;





    }
    catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    return 0;
}