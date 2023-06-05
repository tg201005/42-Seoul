#include "Animal.hpp"

Animal::Animal(void) {
    std::cout << "Animal constructor" << std::endl;
}

Animal::Animal(std::string type) {
    std::cout << "Animal constructor" << std::endl;
    this->type = type;
}

Animal::Animal(Animal const &a) {
    std::cout << "Animal copy constructor" << std::endl;
    *this = a;
}

Animal::~Animal(void) {
    std::cout << "Animal destructor" << std::endl;
}

Animal& Animal::operator=(Animal const &a) {
    std::cout << "Animal assignation operator" << std::endl;
    this->type = a.type;
    return *this;
}

void Animal::makeSound() const {
    std::cout << "Animal sound" << std::endl;
}

std::string Animal::getType() const {
    return this->type;
}

//////////////////////////

Dog::Dog(void) : Animal("Dog") {
    std::cout << "Dog constructor" << std::endl;
}

Dog::Dog(Dog const &d) {
    std::cout << "Dog copy constructor" << std::endl;
    *this = d;
}

Dog::~Dog(void) {
    std::cout << "Dog destructor" << std::endl;
}

Dog& Dog::operator=(Dog const &d) {
    std::cout << "Dog assignation operator" << std::endl;
    this->type = d.type;
    return *this;
}

void Dog::makeSound () const{
    std::cout << "Dog sound" << std::endl;
} 

//////////////////////////

Cat::Cat(void) : Animal("Cat") {
    std::cout << "Cat constructor" << std::endl;
}

Cat::Cat(Cat const &c) {
    std::cout << "Cat copy constructor" << std::endl;
    *this = c;
}

Cat::~Cat(void) {
    std::cout << "Cat destructor" << std::endl;
}

Cat& Cat::operator=(Cat const &c) {
    std::cout << "Cat assignation operator" << std::endl;
    this->type = c.type;
    return *this;
}

void Cat::makeSound () const{
    std::cout << "Cat sound" << std::endl;
}



//////////////////////////


