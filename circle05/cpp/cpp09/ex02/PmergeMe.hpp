#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <list>
#include <map>
#include <ctime>
#include <exception>
#include <sstream>
#include <deque>
#include <climits>
#include <set>
#include <climits>
//usleep header
#include <unistd.h>

template <typename Container>
class PmergeMe{
    private:
        //canonical form
        PmergeMe(const PmergeMe &copy);
        PmergeMe &operator=(const PmergeMe &copy);

        //data
        char **av;
        int depth;
  
        Container unsortedContainer;
        Container mainContainer;
        Container subContainer;
        Container sortedContainer;
        
        void argToContainer();
        void sortContainer();
        void sortMainContainer();
        void sortSubContainer();
        void executeContainer();

        void binarySearch(int value, int length);
        void fillJacobVector(std::vector<int> &jacobVector);


        template <typename T>
        void swapValue(T &mainIt1, T &mainIt2);
        //sort 
        template <typename T>
        void mergeSort(T begin, T end);
        
        template <typename T>
        void Merge(T begin, T mid, T end);

        //validity check
        bool isNumber(std::string str);
        bool isSame();
        bool isSorted();
        bool isSameSize();

        //time_check two functions
        
        clock_t temp;
        clock_t sortTime;

        void timerStart();
        void timerEnd();

        void printContainer(); 

    public:
        //constructor & destructor
        PmergeMe(char **av);
        ~PmergeMe();

        //execute
        void execute();
        void printResult(const std::string &containerName);

};

#include "PmergeMe.tpp"

template class PmergeMe<std::deque<int> >;
template class PmergeMe<std::vector<int> >;

#endif