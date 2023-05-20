#include <iostream>
#include <iomanip> // for setw
#include <string>

class Contact
{
    public:
        Contact();
        ~Contact();
        void set_contact(std::string first_name, std::string last_name, std::string nickname, std::string phone_number, std::string darkest_secret);
        
        // std::string get_first_name();
        // std::string get_last_name();
        // std::string get_nickname();
        // std::string get_phone_number();
        // std::string get_darkest_secret();
        void print_contact(std::string index);

    private:
        std::string first_name;
        std::string last_name;
        std::string nickname;
        std::string phone_number;
        std::string darkest_secret;
};

class PhoneBook
{
    public:
        PhoneBook();
        ~PhoneBook();
        void add_contact();
        void search_contact();
    private:
        Contact contacts[8];
        int nb_contacts;
};