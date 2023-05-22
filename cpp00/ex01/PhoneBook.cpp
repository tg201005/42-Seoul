/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyi <tyi@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 18:10:38 by tyi               #+#    #+#             */
/*   Updated: 2023/05/22 18:46:12 by tyi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void    Contact::set_contact(std::string first_name, std::string last_name, std::string nickname, std::string phone_number, std::string darkest_secret)
{
    this->first_name = first_name;
    this->last_name = last_name;
    this->nickname = nickname;
    this->phone_number = phone_number;
    this->darkest_secret = darkest_secret;
}

std::string truncating(std::string str)
{
    if (str.length() > 10)
        return (str.substr(0, 9) + ".");
    return (str);
}

void    Contact::print_simple_contact(std::string index)
{
    std::cout << std::setw(10) << "Index" << "|";
    std::cout << std::setw(10) << "First name" << "|";
    std::cout << std::setw(10) << "Last name" << "|";
    std::cout << std::setw(10) << "Nickname" << std::endl;
    std::cout << std::setw(10) << index << "|";
    std::cout << std::setw(10) << truncating(this->first_name) << "|";
    std::cout << std::setw(10) << truncating(this->last_name) << "|";
    std::cout << std::setw(10) << truncating(this->nickname) << std::endl;
}

void    Contact::print_contact(std::string index)
{
    std::cout << "Index : " << index << std::endl;
    std::cout << "First name : " << this->first_name << std::endl;
    std::cout << "Last name : " << this->last_name << std::endl;
    std::cout << "Nickname : " << this->nickname << std::endl;
    std::cout << "Phone number : " << this->phone_number << std::endl;
    std::cout << "Darkest secret : " << this->darkest_secret << std::endl;
}

std::string get_line_eof()
{
    std::string line;
    
    std::cout << "here" << std::endl;

    while (true) {
        std::getline(std::cin >> std::ws, line);
        
        if (!line.empty())
            break;
        
        if (std::cin.eof())
            exit(0);
        
        std::cout << "Invalid input" << std::endl;
    }
    
    return line;
}
void   PhoneBook::add_contact()
{
    std::string first_name;
    std::string last_name;
    std::string nickname;
    std::string phone_number;
    std::string darkest_secret;

    std::cout << "Enter first name: " << std::endl; 
    first_name = get_line_eof();

    std::cout << "Enter last name: " << std::endl;
    last_name = get_line_eof();

    std::cout << "Enter nickname: " << std::endl;
    nickname = get_line_eof();

    std::cout << "Enter phone number: " << std::endl;
    phone_number = get_line_eof();

    std::cout << "Enter darkest secret: " << std::endl;
    darkest_secret = get_line_eof();

    contacts[nb_contacts % 8].set_contact(first_name, last_name, nickname, phone_number, darkest_secret);
    nb_contacts++;
}



void    PhoneBook::search_contact()
{
    std::string input;
    int index;

    for (int i = 0; i < nb_contacts; i++)
    {
        if (i == 8 && nb_contacts > 8)
            break ;
        contacts[i].print_simple_contact(std::to_string(i));
    }
    
    std::cout << "Enter index: " << std::endl;
    input = get_line_eof();
    if (!(input == "0" || input == "1" || input == "2" || input == "3" || input == "4" || input == "5" || input == "6" || input == "7"))
    {
        std::cout << "Invalid index" << std::endl;
        return ;
    }
    index = std::stoi(input);
    if (index >= 0 && index < 8)
        contacts[index].print_contact(input);
    else
        std::cout << "Invalid index" << std::endl;
}

Contact::Contact()
{
    this->first_name = "";
    this->last_name = "";
    this->nickname = "";
    this->phone_number = "";
    this->darkest_secret = "";
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
    // //print all contacts
    // for (int i = 0; i < nb_contacts; i++)
    //     contacts[i].print_contact(std::to_string(i));

}

int main(void)
{
    PhoneBook phonebook;
    std::string command;

    while (1)
    {
        std::cout << "--- PHONEBOOK ---" << std::endl;
        std::cout << "Enter a command (ADD, SEARCH, EXIT): " << std::endl;
        command = get_line_eof();

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