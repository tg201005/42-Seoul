#include "Zombie.hpp"

int main()
{
    Zombie *zombie = newZombie("zombie1");
    zombie->announce();
    delete zombie;
    randomChump("zombie2");
    return 0;    
}