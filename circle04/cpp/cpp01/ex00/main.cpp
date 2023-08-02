#include "Zombie.hpp"

int main()
{
    Zombie *zombie = newZombie("zombie1 heap");
    zombie->announce();
    delete zombie;

    randomChump("zombie2 by stack");
    return 0;    
}