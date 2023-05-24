#include "Fixed.hpp"

Fixed::Fixed(){
    std::cout << "Default constructor called" << std::endl;
    this->fixed_point_value = 0;
}

Fixed::~Fixed(){
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fixed){
    std::cout << "Copy constructor called" << std::endl;
    this->fixed_point_value = fixed.getRawBits();
}

Fixed::Fixed(const int value){
    std::cout << "Int constructor called" << std::endl;
    this->fixed_point_value = value << this->fractional_bits;
}

Fixed::Fixed(const float value){
    std::cout << "Float constructor called" << std::endl;
    this->fixed_point_value = roundf(value * (1 << this->fractional_bits));
}


Fixed&    Fixed::operator=(const Fixed &fixed){
    
    std::cout <<"Copy operator called" << std::endl;
    this->fixed_point_value = fixed.getRawBits();
    return (*this);
}


float   Fixed::toFloat() const{
    return (static_cast<float>(this->getRawBits()) / (1 << this->fractional_bits));
}

int     Fixed::toInt() const{
    return (static_cast<int>(this->getRawBits()) >> this->fractional_bits);
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed){
    os << fixed.toFloat();
    return (os);
}

int     Fixed::getRawBits(void) const{
    std::cout << "getRawBits member function called" << std::endl;
    return (this->fixed_point_value);
}

void    Fixed::setRawBits(int const raw){
    std::cout << "setRawBits member function called" << std::endl;
    this->fixed_point_value = raw;
}
