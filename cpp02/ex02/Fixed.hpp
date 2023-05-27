#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>


class Fixed{

    private:
        int fixed_point_value;
        static const int fractional_bits = 8;
    
    public:
        Fixed();
        Fixed(const Fixed &fixed);
        Fixed(const int value);
        Fixed(const float value);

        ~Fixed();

        Fixed& operator=(const Fixed &fixed);
        
        bool operator>(const Fixed &fixed) const;
        bool operator<(const Fixed &fixed) const;
        bool operator>=(const Fixed &fixed) const;
        bool operator<=(const Fixed &fixed) const;
        bool operator==(const Fixed &fixed) const;
        bool operator!=(const Fixed &fixed) const;

        Fixed operator+(const Fixed &fixed) const;
        Fixed operator-(const Fixed &fixed) const;
        Fixed operator*(const Fixed &fixed) const;
        Fixed operator/(const Fixed &fixed) const;

        Fixed& operator++();
        Fixed operator++(int);
        Fixed& operator--();
        Fixed operator--(int);

        float   toFloat() const;
        int     toInt() const;
        int     getRawBits(void) const;
        void    setRawBits(int const raw);


        static Fixed& min(Fixed &a, Fixed &b);
        const static Fixed& min(const Fixed &a, const Fixed &b);
        static Fixed& max(Fixed &a, Fixed &b);
        const static Fixed& max(const Fixed &a, const Fixed &b);


};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif