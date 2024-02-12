#include "Zombie.hpp"

int main()
{
    Zombie* zombi;

    zombi = zombieHorde(5, "Test Zombie");
    std::cout << "Zombie horde created" << std::endl;
    for (int i = 0; i < 5; i++)
        zombi[i].announce();
    delete[] zombi;
}