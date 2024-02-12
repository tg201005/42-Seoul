#include "Animal.hpp"
#include "WrongAnimal.hpp"

void checkLeaks()
{
    system("leaks a.out");
}

int main()
{
    int animalCount = 10;
    Animal* animals[animalCount];
    Dog dog;

    // Create and fill the array with Dogs and Cats
    for (int i = 0; i < animalCount / 2; i++) {
        animals[i] = new Dog(dog);
    }


    for (int i = animalCount / 2; i < animalCount; i++) {
        animals[i] = new Cat();
    }
    
    std::cout << "-------------" <<std::endl;

    // Delete the animals array
    for (int i = 0; i < animalCount; i++) {
        delete animals[i];
        std::cout << "deleted animal : " << i << std::endl;
    }

    atexit(checkLeaks);
    return 0;
}