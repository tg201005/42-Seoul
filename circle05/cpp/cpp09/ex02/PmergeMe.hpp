#include <iostream>
#include <string>


class PmergeMe
{
    private:
        //canonical form
        PmergeMe(const PmergeMe &copy);
        PmergeMe &operator=(const PmergeMe &copy);

    public:
        //constructor & destructor
        PmergeMe(std::string const &av);
        ~PmergeMe();

        //data set
        fillIntVector(char **av);

        //sorting
        sort1();
        sort2();

        //display
        display();

        //error handling




};