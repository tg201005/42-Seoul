#include "ex01.hpp"

void    Contact::set_contact(std::string first_name, std::string last_name, std::string nickname, std::string phone_number, std::string darkest_secret)
{
    this->first_name = first_name;
    this->last_name = last_name;
    this->nickname = nickname;
    this->phone_number = phone_number;
    this->darkest_secret = darkest_secret;
}
void    Contact::print_contact(std::string index)
{
    std::cout << std::setw(10) << "Index" << "|";
    std::cout << std::setw(10) << "First name" << "|";
    std::cout << std::setw(10) << "Last name" << "|";
    std::cout << std::setw(10) << "Nickname" << std::endl;
    std::cout << std::setw(10) << index << "|";
    std::cout << std::setw(10) << this->first_name << "|";
    std::cout << std::setw(10) << this->last_name << "|";
    std::cout << std::setw(10) << this->nickname << std::endl;
}


void   PhoneBook::add_contact()
{
    Contact new_contact;

    new_contact = contacts[nb_contacts % 8];

    std::string first_name;
    std::string last_name;
    std::string nickname;
    std::string phone_number;
    std::string darkest_secret;

    std::cout << "Enter first name: " << std::endl;
    std::cin >> first_name;

    std::cout << "Enter last name: " << std::endl;
    std::cin >> last_name;

    std::cout << "Enter nickname: " << std::endl;
    std::cin >> nickname;

    std::cout << "Enter phone number: " << std::endl;
    std::cin >> phone_number;

    std::cout << "Enter darkest secret: " << std::endl;
    std::cin >> darkest_secret;

    new_contact.set_contact(first_name, last_name, nickname, phone_number, darkest_secret);
    nb_contacts++;
}


void    PhoneBook::search_contact()
{
    std::string input;
    int index;
    Contact search_contact;

    std::cout << "Enter index: " << std::endl;
    std::cin >> input;
    index = std::stoi(input);
    search_contact = contacts[index];
    if (index >= 0 && index < 8)
        search_contact.print_contact(input);
    else
        std::cout << "Invalid index" << std::endl;
}

Contact::Contact()
{
    std::string first_name = "";
    std::string last_name = "";
    std::string nickname = "";
    std::string phone_number = "";
    std::string darkest_secret = "";
}

Contact::~Contact()
{
}

PhoneBook::PhoneBook()
{
    nb_contacts = 0;
}

PhoneBook::~PhoneBook()
{
    Contact now_contact;
    //print_all_contacts();
    for (int i = 0; i < nb_contacts; i++)
    {
        now_contact = contacts[i];
        now_contact.print_contact(std::to_string(i));
    }
}

int main(void)
{
    PhoneBook phonebook;
    std::string command;

    while (1)
    {
        std::cout << "Enter a command (ADD, SEARCH, EXIT): " << std::endl;
        std::cin >> command;
        if (command == "EXIT")
            break ;
        else if (command == "ADD")
            phonebook.add_contact();
        else if (command == "SEARCH")
            phonebook.search_contact();
        else
            std::cout << "Invalid command" << std::endl;
    }
    return (0);
}