#include <iostream>
#include <string>

class Brain
{
    private:
        std::string ideas[100];
    
    public:
        Brain();
        Brain(Brain const &b);
        ~Brain();

        Brain& operator=(Brain const &b);
};