#include <iostream>
#include <iomanip> // for setw
#include <string>

class Contact {
public:
    Contact() : firstName(""), lastName(""), nickname(""), phoneNumber(""), darkestSecret("") {}

    void setContact(const std::string& firstName, const std::string& lastName, const std::string& nickname, const std::string& phoneNumber, const std::string& darkestSecret) {
        this->firstName = firstName;
        this->lastName = lastName;
        this->nickname = nickname;
        this->phoneNumber = phoneNumber;
        this->darkestSecret = darkestSecret;
    }


std::string getFirstName() const {
    return firstName;
}

std::string getLastName() const {
    return lastName;
}

std::string getNickname() const {
    return nickname;
}

std::string getPhoneNumber() const {
    return phoneNumber;
}

std::string getDarkestSecret() const {
    return darkestSecret;
} 

private:
    std::string firstName;
    std::string lastName;
    std::string nickname;
    std::string phoneNumber;
    std::string darkestSecret;
};

class PhoneBook {
public:
    PhoneBook() : contactCount(0) {}

    void addContact(const Contact& contact) {
        if (contactCount >= 8) {
            // Replace the oldest contact by shifting the array
            for (int i = 0; i < 7; ++i) {
                contacts[i] = contacts[i + 1];
            }
            contacts[7] = contact;
        } else {
            contacts[contactCount] = contact;
            ++contactCount;
        }
    }

    void displayContacts() const {
        std::cout << std::right << std::setw(10) << "Index" << " | "
                  << std::setw(10) << "First Name" << " | "
                  << std::setw(10) << "Last Name" << " | "
                  << std::setw(10) << "Nickname" << std::endl;

        for (int i = 0; i < contactCount; ++i) {
            std::cout << std::right << std::setw(10) << i << " | "
                      << std::setw(10) << truncateString(contacts[i].getFirstName()) << " | "
                      << std::setw(10) << truncateString(contacts[i].getLastName()) << " | "
                      << std::setw(10) << truncateString(contacts[i].getNickname()) << std::endl;
        }
    }

    void searchContact(int index) const {
        if (index >= 0 && index < contactCount) {
            const Contact& contact = contacts[index];
            std::cout << "First Name: " << contact.getFirstName() << std::endl;
            std::cout << "Last Name: " << contact.getLastName() << std::endl;
            std::cout << "Nickname: " << contact.getNickname() << std::endl;
            std::cout << "Phone Number: " << contact.getPhoneNumber() << std::endl;
            std::cout << "Darkest Secret: " << contact.getDarkestSecret() << std::endl;
        } else {
            std::cout << "Invalid index!" << std::endl;
        }
    }

private:
    Contact contacts[8];
    int contactCount;

    std::string truncateString(const std::string& str) const {
        if (str.length() <= 10)
            return str;
        else
            return str.substr(0, 9) + ".";
    }
};

void    print_PhoneBook(PhoneBook *phonebook)
{
    int i = 0;
    std::cout << "     index|first name| last name|  nickname" << std::endl;
    while (i < 8)
    {
        std::cout << std::setw(10) << i << "|";
        std::cout << std::setw(10) << phonebook[i].getFirstName() << "|";
        std::cout << std::setw(10) << phonebook[i].getLastName() << "|";
        std::cout << std::setw(10) << phonebook[i].getNickname() << std::endl;
        i++;
    }
}


void    init_PhoneBook(PhoneBook *phonebook)
{
    int i = 0;
    while (i < 8)
    {
        phonebook[i].setContact("", "", "", "", "");
        i++;
    }
}

int main() {
    PhoneBook phoneBook;
    std::string command;

    // while (
    // std::cout << "Welcome to the 80s and their unbelievable technology!" << std::endl;
    // std::cout << "Write a program that behaves like a crappy awesome phonebook software." << std::endl;

    while (true) {
        std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
        std::cin >> command;

        if (command == "ADD") {
            std::string firstName, lastName, nickname, phoneNumber, darkestSecret;

            std::cout << "Enter the first name: ";
            std::cin >> firstName;

            std::cout << "Enter the last name: ";
            std::cin >> lastName;

            std::cout << "Enter the nickname: ";
            std::cin >> nickname;

            std::cout << "Enter the phone number: ";
            std::cin >> phoneNumber;

            std::cout << "Enter the darkest secret: ";
            std::cin.ignore(); // Ignore the newline character left in the input buffer
            std::getline(std::cin, darkestSecret);
    //please explain 115~116 code
    

            Contact newContact;
            newContact.setContact(firstName, lastName, nickname, phoneNumber, darkestSecret);
            phoneBook.addContact(newContact);
        } else if (command == "SEARCH") {
            phoneBook.displayContacts();

            int index;
            std::cout << "Enter the index of the contact to display: ";
            std::cin >> index;

            phoneBook.searchContact(index);
        } else if (command == "EXIT") {
            break;
        } else {
            std::cout << "Invalid command!" << std::endl;
        }
    }

    std::cout << "Program ended. Contacts are lost forever!" << std::endl;

    return 0;
}
