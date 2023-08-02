#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) {
    std::cout << "WrongAnimal constructor" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) {
    std::cout << "WrongAnimal constructor" << std::endl;
    this->type = type;
}

WrongAnimal::WrongAnimal(WrongAnimal const &a) {
    std::cout << "WrongAnimal copy constructor" << std::endl;
    *this = a;
}

WrongAnimal::~WrongAnimal(void) {
    std::cout << "WrongAnimal destructor" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(WrongAnimal const &a) {
    std::cout << "WrongAnimal assignation operator" << std::endl;
    this->type = a.type;
    return *this;
}

void WrongAnimal::makeSound () const{
    std::cout << "WrongAnimal sound" << std::endl;
}

std::string WrongAnimal::getType() const {
    return this->type;
}

//////////////////////////

WrongCat::WrongCat(void) : WrongAnimal("WrongCat") {
    std::cout << "WrongCat constructor" << std::endl;
}

WrongCat::WrongCat(WrongCat const &c) {
    std::cout << "WrongCat copy constructor" << std::endl;
    *this = c;
}

WrongCat::~WrongCat(void) {
    std::cout << "WrongCat destructor" << std::endl;
}

WrongCat& WrongCat::operator=(WrongCat const &c) {
    std::cout << "WrongCat assignation operator" << std::endl;
    this->type = c.type;
    return *this;
}

void WrongCat::makeSound() const{
    std::cout << "WrongCat sound" << std::endl;
}

