#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <exception>


class BitcoinExchange
{
private:

    //canonical form
    BitcoinExchange(const BitcoinExchange &copy);
    BitcoinExchange &operator=(const BitcoinExchange &copy);

    //database
    std::map<long, float> database;

    //file
    std::string priceFile;
    std::string amountFile;

    //function
    std::vector<std::string> splitString(const std::string& str, char delimiter);
    long getClosetDate(const std::string& targetDate);

    //
    long getClosetDay(const std::string& target_date);
    void printCalculation(const std::string& date, int amount);
    
    
    void readPriceDatabase();
    void readAmountDatabase();
    long getDay(const std::string& date);

    
public:
    BitcoinExchange(std::string priceFile, std::string amountFile);
    ~BitcoinExchange();
    void value_calculator();


};

#endif // BITCOINEXCHANGE_HPP
