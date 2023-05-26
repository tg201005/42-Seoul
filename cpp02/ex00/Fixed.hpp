#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>


class Fixed{

    private:
        int fixed_point_value;
        static const int fractional_bits = 8;
    
    public:
        Fixed();
        ~Fixed();
        Fixed(Fixed &fixed);
        
        //we need to toss the instance of the class to the copy constructor
        Fixed& operator=(Fixed &fixed);
        
        int getRawBits(void) const;
        void setRawBits(const int raw);
};

#endif