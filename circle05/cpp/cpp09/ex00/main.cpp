#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
    if (argc != 2){
        std::cout << "Error: bad arguments." << std::endl;
        return 1;
    }

    const std::string priceFile = "data.csv";
    const std::string amountFile = argv[1];

    BitcoinExchange bitcoinExchange(priceFile, amountFile);
    try {
        bitcoinExchange.value_calculator();
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}