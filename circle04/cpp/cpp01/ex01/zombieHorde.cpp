#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
    Zombie* zombi;
    
    zombi = new Zombie[N];
    for (int i = 0; i < N; i++)
    {
        std::cout << "Zombie " << i << " created" << std::endl;
        zombi[i].set_name(name);
    }
    return (zombi);
}
