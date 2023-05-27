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
    this->fixed_point_value = std::roundf(value * (1 << this->fractional_bits));
}

///////////////////////////

Fixed&    Fixed::operator=(const Fixed &fixed){
    
    std::cout <<"Copy operator called" << std::endl;
    this->fixed_point_value = fixed.getRawBits();
    return (*this);
}

///////////////////////////

float   Fixed::toFloat() const{
    return (static_cast<float>(this->getRawBits()) / (1 << this->fractional_bits));
}

//부동 소수점으로 나타난 float 혹은 double 값에 대해선 비트 연산이 작동하지 않기 때문에

int     Fixed::toInt() const{
    return (static_cast<int>(this->getRawBits()) >> this->fractional_bits);
}

///////////////////////////

int     Fixed::getRawBits(void) const{
    // std::cout << "getRawBits member function called" << std::endl;
    return (this->fixed_point_value);
}

void    Fixed::setRawBits(int const raw){
    // std::cout << "setRawBits member function called" << std::endl;
    this->fixed_point_value = raw;
}

///////////////////////////

//fixed format of << operator overloading

std::ostream& operator<<(std::ostream& os, const Fixed& fixed){
    os << fixed.toFloat();
    return (os);
}
