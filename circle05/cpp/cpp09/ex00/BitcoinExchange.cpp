#include "BitcoinExchange.hpp"

//canonical form
BitcoinExchange::BitcoinExchange(std::string priceFile, std::string amountFile)
{
    this->priceFile = priceFile;
    this->amountFile = amountFile;
    
    readPriceDatabase();
}

BitcoinExchange::~BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy)
{
    *this = copy;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &copy)
{
    if (this != &copy)
    {
        this->priceFile = copy.priceFile;
        this->amountFile = copy.amountFile;
        this->database = copy.database;
    }
    return *this;
}  

//function

bool isValidDate(const std::string& date)
{
    if (date.length() != 10)
        return false;

    if (date[4] != '-' || date[7] != '-')
        return false;

    int year = atoi(date.substr(0, 4).c_str());
    int month = atoi(date.substr(5, 2).c_str());
    int day = atoi(date.substr(8, 2).c_str());

    if (year < 0 || month < 1 || month > 12 || day < 1 || day > 31)
        return false;

    // Additional logic to check for valid dates based on the month and year can be added here

    return true;
}

void BitcoinExchange::printCalculation(const std::string& date, int amount)
{

    //check data valid
    if (!isValidDate(date))
    {
        std::cout << "Error: bad input => " << date << std::endl;
        return;
    }

    //check amount valid
    if (amount <= 0){
        std::cout << "Error: not a positive number." << std::endl;
        return;
    }
    else if (amount > 1000){
        std::cout << "Error: too large a number." << std::endl;
        return;
    }

    //check price valid
    float price = this->database[getClosetDate(date)];
    if (price <= 0){
        std::cout << "Error: not a positive number." << std::endl;
        return;
    }

    
    //print calculation
    std::cout << date << " => " << amount << " = " << amount * price << std::endl;
    return ;
}



//get closest date
long BitcoinExchange::getClosetDate(const std::string& targetDate)
{
    //lopwer_bound

    std::map<long, float>::iterator lower = this->database.lower_bound(getDay(targetDate));
    if (lower == this->database.begin())
        return lower->first;
    if (lower == this->database.end())
    {
        std::map<long, float>::iterator prev = lower;
        --prev;
        return prev->first;
    }
    std::map<long, float>::iterator prev = lower;
    --prev;
    if (getDay(targetDate) - prev->first < lower->first - getDay(targetDate))
        return prev->first;
    return lower->first;

}

//read database only price file

void BitcoinExchange::readPriceDatabase()
{
    std::ifstream file(this->priceFile.c_str());
    if (!file.is_open())
    {
        std::cout << "Error: could not open file." << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line))
    {
        //not using vector separate with , only with cpp98
        std::string date = line.substr(0, line.find(','));
        std::string price = line.substr(line.find(',') + 1, line.length());

        //insert database
        std::stringstream ss;
        float price_float;
        ss >> price_float;
        this->database[getDay(date)] = price_float;  
    }
}

void BitcoinExchange::readAmountDatabase()
{
    std::ifstream file(this->amountFile.c_str());
    if (!file.is_open())
    {
        std::cout << "Error: could not open file." << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line))
    {
        std::string date = line.substr(0, line.find(','));
        std::string amount = line.substr(line.find(',') + 1, line.length());

        //string to int with string stream
        std::stringstream ss;
        ss << amount;
        int amount_int;
        ss >> amount_int; 
        //print calculation

        printCalculation(date, amount_int);
    }
}

//make string to long function with string stream

long stolong(const std::string& str)
{
    std::stringstream ss;
    ss << str;
    long result;
    ss >> result;
    return result;
}

long BitcoinExchange::getDay(const std::string& date)
{
    //not using vector, splitString, separte with -, only with cpp98

    long year = stolong(date.substr(0, 4));
    long month = stolong(date.substr(5, 2));
    long day_ = stolong(date.substr(8, 2));

    long day = 0;
    for (int i = 0; i < year; i++)
    {
        if (i % 4 == 0)
            day += 366;
        else
            day += 365;
    }
    for (int i = 0; i < month; i++)
    {
        if (i == 2)
        {
            if (year % 4 == 0)
                day += 29;
            else
                day += 28;
        }
        else if (i == 4 || i == 6 || i == 9 || i == 11)
            day += 30;
        else
            day += 31;
    }
    day += day_;
    return day;
}

void BitcoinExchange::value_calculator()
{
    readAmountDatabase();
}