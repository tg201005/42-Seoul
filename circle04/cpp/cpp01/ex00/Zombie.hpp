#include <iostream>
#include <string>

class Zombie{
    public:
        Zombie();
        ~Zombie();
        void    announce();
        void    set_name(std::string name);
    private:
        std::string name;
};

Zombie* newZombie(std::string name);
void    randomChump(std::string name);