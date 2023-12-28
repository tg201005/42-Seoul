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


bool isLeapYear(int year)
{
    if (year % 4 != 0) // 4로 나누어 떨어지지 않으면 윤년이 아님
        return false;
    else if (year % 100 != 0) // 4로 나누어 떨어지지만 100으로 나누어 떨어지지 않으면 윤년
        return true;
    else if (year % 400 != 0) // 100으로 나누어 떨어지지만 400으로 나누어 떨어지지 않으면 윤년이 아님
        return false;
    else // 400으로 나누어 떨어지면 윤년
        return true;
}

bool isValidDateWithLeapYear(const std::string& date)
{
    if (date.length() != 10)
    {
        return false;
    }
    if (date[4] != '-' || date[7] != '-')
    {
        return false;
    }
    std::stringstream ss(date);

    long year, month, day;

    ss >> year;
    ss.ignore(1);
    ss >> month;
    ss.ignore(1);
    ss >> day;

    if (year < 0 || month < 1 || month > 12 || day < 1 || day > 31)
        return false;

    // 윤년을 고려하여 각 월의 일 수를 체크
    if (month == 2) // 2월인 경우
    {
        if (isLeapYear(year)) // 윤년인 경우
        {
            if (day > 29) // 29일을 초과하면 유효하지 않음
                return false;
        }
        else // 윤년이 아닌 경우
        {
            if (day > 28) // 28일을 초과하면 유효하지 않음
                return false;
        }
    }
    else if (month == 4 || month == 6 || month == 9 || month == 11) // 4, 6, 9, 11월인 경우
    {
        if (day > 30) // 30일을 초과하면 유효하지 않음
            return false;
    }

    return true;
}

void BitcoinExchange::printCalculation(const std::string& date, float amount)
{
    //print date amount 

    //check data valid
    if (!isValidDateWithLeapYear(date))
    {
        std::cout << "Error: bad input => " << date << std::endl;
        return;
    }

    //check amount valid
    if (amount <= 0){
        std::cout << "Error: not a positive number." << std::endl;
        return;
    }
    
    if (amount > 1000){
        std::cout << "Error: too large a number." << std::endl;
        return;
    }

    //check price valid

    float price;
    try {
        price = this->database[getClosetDate(date)];
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
        return;
    }

    std::cout << date << " => " << amount << " = " << amount * price << std::endl;
    return ;
}



//get closest date
long BitcoinExchange::getClosetDate(const std::string& targetDate)
{
//If the date used in the input does not exist in your DB then you must use the closest date contained in your DB. Be careful to use the lower date and not the upper one. using with only cpp98

    
    
    long targetDay = getDay(targetDate);

    long closestDay = 0;

    //start form the end of map, 
    std::map<long, float>::reverse_iterator it;
    for (it = this->database.rbegin(); it != this->database.rend(); it++)
    {
        if (it->first <= targetDay)
        {
            closestDay = it->first;
            break;
        }
    }

    if (it == this->database.rend())
        throw std::invalid_argument("Error: no data available for this date.");

    
    return closestDay;
}

//read database only price file

void BitcoinExchange::readPriceDatabase()
{
    std::ifstream file(this->priceFile.c_str());
    if (!file.is_open())
    {
        throw std::runtime_error("Error: could not open file.");
        return;
    }

    std::string line;
    while (std::getline(file, line))
    {
        if (line.empty())
            continue;

        //not using vector separate with , only with cpp98
        std::string date = line.substr(0, line.find(','));
        std::string price = line.substr(line.find(',') + 1, line.length());

        //white space remove only under cpp98
        date.erase(std::remove(date.begin(), date.end(), ' '), date.end());
        price.erase(std::remove(price.begin(), price.end(), ' '), price.end());

        //if date,exchange_rate , continue
        if (date == "date" && price == "exchange_rate")
            continue;
            

        //insert database
        //string to float with string stream
        std::stringstream ss;
        ss << price;
        float price_float;
        ss >> price_float;

        if (ss.fail() || !ss.eof())
        {
            std::cout << "Error: bad input => " << date << " | " << price << std::endl;
            continue;
        }
    
        this->database[getDay(date)] = price_float;  
    }
}

void BitcoinExchange::readAmountDatabase()
{
    std::ifstream file(this->amountFile.c_str());
    if (!file.is_open())
    {
        throw std::runtime_error("Error: could not open file.");
    }

    std::string line;
    while (std::getline(file, line))
    {

        if (line.empty()) {
            std::cout << "----" << std::endl;
            continue;
        }

        std::string date = line.substr(0, line.find('|'));
        std::string amount = line.substr(line.find('|') + 1, line.length());
        
        date.erase(std::remove(date.begin(), date.end(), ' '), date.end());
        amount.erase(std::remove(amount.begin(), amount.end(), ' '), amount.end());
        
        if (date == "date" && amount == "value")
            continue;
        
        //string to int with string stream
        std::stringstream ss;
        ss << amount;
        float amount_float;
        ss >> amount_float; 

        if (ss.fail() || !ss.eof())
        {
            std::cout << "Error: bad input => " << date << " | " << amount << std::endl;
            continue;
        }
        printCalculation(date, amount_float);
    }
}

//make string to long function with string stream

long stolong(const std::string& str)
{
    //ussing string stream separte with -, only with cpp98

    std::stringstream ss;
    ss << str;
    long result;
    ss >> result;
    return result;

}

long BitcoinExchange::getDay(const std::string& date)
{
    
    if (date.length() != 10)
    {
        throw std::invalid_argument("Error: bad input => " + date);
    }

    if (date[4] != '-' || date[7] != '-')
    {
        throw std::invalid_argument("Error: bad input => " + date);
    }
    std::stringstream ss(date);
   
    long year;
    long month;
    long day_;
    
    ss >> year;
    ss.ignore(1);
    ss >> month;
    ss.ignore(1);
    ss >> day_;

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

void BitcoinExchange::printDatabase()
{
    for (std::map<long, float>::iterator it = this->database.begin(); it != this->database.end(); it++)
    {
        std::cout << it->first << " => " << it->second << std::endl;
    }
}