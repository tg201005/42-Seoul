#include <iostream>
#include <string>


class   Harl{
    private:
        void    debug();
        void    info();
        void    warning();
        void    error();

    public:
        void    complain_level(std::string level);
};