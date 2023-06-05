#include "Animal.hpp"
#include "WrongAnimal.hpp"

int main()
{
    int animalCount = 10;
    Animal* animals[animalCount];

    // Create and fill the array with Dogs and Cats
    for (int i = 0; i < animalCount / 2; i++) {
        animals[i] = new Dog();
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

    return 0;
}