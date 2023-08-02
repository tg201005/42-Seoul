#include "iostream"
#include "string"


class Zombie{
    public:
        Zombie();
        ~Zombie();
        void    announce();
        void    set_name(std::string name);
    private:
        std::string name;
};

Zombie* zombieHorde(int N, std::string name);