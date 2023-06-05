#include "Brain.hpp"

Brain::Brain(void) {
    std::cout << "Brain constructor" << std::endl;
}

Brain::Brain(Brain const &b) {
    std::cout << "Brain copy constructor" << std::endl;
    *this = b;
}

Brain::~Brain(void) {
    std::cout << "Brain destructor" << std::endl;
}

Brain& Brain::operator=(Brain const &b) {
    std::cout << "Brain assignation operator" << std::endl;
    for (int i = 0; i < 100; i++)
        this->ideas[i] = b.ideas[i];
    return *this;
}

