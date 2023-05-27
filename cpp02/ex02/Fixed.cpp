/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyi <tyi@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 12:51:24 by tyi               #+#    #+#             */
/*   Updated: 2023/05/27 16:26:37 by tyi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Fixed.hpp"

Fixed::Fixed(){
    // std::cout << "Default constructor called" << std::endl;
    this->fixed_point_value = 0;
}

Fixed::Fixed(const Fixed &fixed){
    // std::cout << "Copy constructor called" << std::endl;
    this->fixed_point_value = fixed.getRawBits();
}

Fixed::Fixed(const int value){
    // std::cout << "Int constructor called" << std::endl;
    this->fixed_point_value = value << this->fractional_bits;
}

Fixed::Fixed(const float value){
    // std::cout << "Float constructor called" << std::endl;
    this->fixed_point_value = roundf(value * (1 << this->fractional_bits));
}

Fixed::~Fixed(){
    // std::cout << "Destructor called" << std::endl;
}

////////////

Fixed&    Fixed::operator=(const Fixed &fixed){
    
    std::cout <<"Copy operator called" << std::endl;
    this->fixed_point_value = fixed.getRawBits();
    return (*this);
}


bool    Fixed::operator>(const Fixed &fixed) const{
    return (this->getRawBits() > fixed.getRawBits());
}

bool    Fixed::operator<(const Fixed &fixed) const{
    return (this->getRawBits() < fixed.getRawBits());
}

bool    Fixed::operator>=(const Fixed &fixed) const{
    return (this->getRawBits() >= fixed.getRawBits());
}

bool    Fixed::operator<=(const Fixed &fixed) const{
    return (this->getRawBits() <= fixed.getRawBits());
}

bool    Fixed::operator==(const Fixed &fixed) const{
    return (this->getRawBits() == fixed.getRawBits());
}

bool    Fixed::operator!=(const Fixed &fixed) const{
    return (this->getRawBits() != fixed.getRawBits());
}


////////////


Fixed   Fixed::operator+(const Fixed &fixed) const{
    return (Fixed(this->toFloat() + fixed.toFloat()));
}

Fixed   Fixed::operator-(const Fixed &fixed) const{
    return (Fixed(this->toFloat() - fixed.toFloat()));
}

Fixed   Fixed::operator*(const Fixed &fixed) const{
    return (Fixed(this->toFloat() * fixed.toFloat()));
}

Fixed   Fixed::operator/(const Fixed &fixed) const{
    return (Fixed(this->toFloat() / fixed.toFloat()));
}


////////////

// ++a
Fixed&  Fixed::operator++(){
    this->fixed_point_value++;
    return (*this);
}

// a++
Fixed   Fixed::operator++(int){
    Fixed tmp(*this);
    operator++();
    return (tmp);
}

Fixed&  Fixed::operator--(){
    this->fixed_point_value--;
    return (*this);
}

Fixed   Fixed::operator--(int){
    Fixed tmp(*this);
    operator--();
    return (tmp);
}


////////////


float   Fixed::toFloat() const{
    return (static_cast<float>(this->getRawBits()) / (1 << this->fractional_bits));
}

int     Fixed::toInt() const{
    return (static_cast<int>(this->getRawBits()) >> this->fractional_bits);
}

int     Fixed::getRawBits(void) const{
    // std::cout << "getRawBits member function called" << std::endl;
    return (this->fixed_point_value);
}

void    Fixed::setRawBits(int const raw){
    this->fixed_point_value = raw;
}


////////////

static Fixed&    min(Fixed &a, Fixed &b){
    return (a < b ? a : b);
}

const static Fixed&    min(const Fixed &a, const Fixed &b){
    return (a < b ? const_cast<Fixed&>(a) : const_cast<Fixed&>(b));
}

static Fixed&    max(Fixed &a, Fixed &b){
    return (a > b ? a : b);
}

const static Fixed&    max(const Fixed &a, const Fixed &b){
    return (a > b ? const_cast<Fixed&>(a) : const_cast<Fixed&>(b));
}


////////////


std::ostream& operator<<(std::ostream& os, const Fixed& fixed){
    os << fixed.toFloat();
    return (os);
}