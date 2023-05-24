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
        Fixed(int const value);
        Fixed(float const value);
        ~Fixed();

        Fixed& operator=(const Fixed &fixed);

        float toFloat() const;
        int toInt() const;

        int getRawBits(void) const;
        void setRawBits(int const raw);
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif