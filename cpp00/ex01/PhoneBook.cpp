/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyi <tyi@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 18:10:38 by tyi               #+#    #+#             */
/*   Updated: 2023/05/21 20:02:01 by tyi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ex01.hpp"

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

void    Contact::print_contact(std::string index)
{
    std::cout << std::setw(10) << "Index" << "|";
    std::cout << std::setw(10) << "First name" << "|";
    std::cout << std::setw(10) << "Last name" << "|";
    std::cout << std::setw(10) << "Nickname" << std::endl;
    std::cout << std::setw(10) << index << "|";
    std::cout << std::setw(10) << truncating(this->first_name) << "|";
    std::cout << std::setw(10) << truncating(this->last_name) << "|";
    std::cout << std::setw(10) << truncating(this->nickname) << std::endl;

    // // check phone number and darkest secret
    // std::cout << "Phone number : " << this->phone_number << std::endl;
    // std::cout << "darkest_secret" << this->darkest_secret << std::endl;

}

void   PhoneBook::add_contact()
{
    std::string first_name;
    std::string last_name;
    std::string nickname;
    std::string phone_number;
    std::string darkest_secret;

    std::cout << "Enter first name: " << std::endl; 
    // std::cin >> (first_name);
    std::getline(std::cin, first_name);

    std::cout << "Enter last name: " << std::endl;
    // std::cin >> (last_name);
    std::getline(std::cin, last_name);

    std::cout << "Enter nickname: " << std::endl;
    // std::cin >> (nickname);
    std::getline(std::cin, nickname);

    std::cout << "Enter phone number: " << std::endl;
    // std::cin.ignore();
    std::getline(std::cin, phone_number);

    std::cout << "Enter darkest secret: " << std::endl;
    // std::cin >> (darkest_secret);
    std::getline(std::cin, darkest_secret);

    contacts[nb_contacts % 8].set_contact(first_name, last_name, nickname, phone_number, darkest_secret);
    nb_contacts++;
}



void    PhoneBook::search_contact()
{
    std::string input;
    int index;
    Contact search_contact;

    std::cout << "Enter index: " << std::endl;
    std::cin >> (input);
    index = std::stoi(input);
    search_contact = contacts[index];
    if (index >= 0 && index < 8)
        search_contact.print_contact(input);
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
        std::cout << "Out program don't supprot spaces in input" << std::endl;
        std::cout << "Enter a command (ADD, SEARCH, EXIT): " << std::endl;
        std::getline(std::cin, command);

        std::cout << "command: " << command << std::endl;
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