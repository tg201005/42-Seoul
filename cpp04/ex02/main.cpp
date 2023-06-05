#include "Animal.hpp"
#include "WrongAnimal.hpp"

int main()
{
    // const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); //will output the cat sound!
    j->makeSound();
    // meta->makeSound();

    // delete meta;
    delete j;
    delete i;

    std::cout << "---------------------" << std::endl;
    const WrongAnimal* k = new WrongAnimal();
    const WrongAnimal* q = new WrongCat();
    std::cout << k->getType() << " " << std::endl;
    std::cout << q->getType() << " " << std::endl;

    q->makeSound();
    k->makeSound();

    delete k;
    delete q;

    return 0;
}