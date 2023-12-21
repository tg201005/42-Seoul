#include "PmergeMe.hpp"
PmergeMe::PmergeMe(char **av){
    this->av = av;
    depth = 0;
}

PmergeMe::~PmergeMe(){}


//length of iterator begin to end

template <typename T>
int lengthIterator(T begin, T end){
    int length = 0;
    while (begin != end){
        length++;
        begin++;
    }
    return length;
}

template <typename T>
void moveIterator(T &begin, int n){
    while (n > 0){
        begin++;
        n--;
    }
}

template <typename T>
void printIterator(T begin, T end){
    while (begin != end){
        std::cout << *begin << " ";
        begin++;
    }
    std::cout << "\n";
}


template <typename T>
void PmergeMe::mergeSort(T begin, T end)
{
    
    if (begin == end)
        return ;

    depth++;
    printIterator(begin, end);
    std::cout << "depth: " << depth << "\n"; //depth: 0

    T mid = begin;
    int length = lengthIterator(begin, end);
    moveIterator(mid, length/2);   

    T temp = mid;
    temp ++;

    mergeSort(begin, mid);
    mergeSort(temp, end);
    Merge(begin, mid, end);
}

template <typename T>
void swapValue(T &it1, T &it2){
    int temp = *it1;
    *it1 = *it2;
    *it2 = temp;
}

template <typename T>
void PmergeMe::Merge(T begin, T mid, T end)
{
    //implement insertion sort with iterator

    (void) mid;
    T current = begin;
    while (begin != end)
    {
        current = begin;
        while (current != end)
        {
            if (*begin > *current)
                swapValue(begin, current);
            current++;
        }
        begin++;
    }
}

void PmergeMe::argToVector()
{
    int i = 1;
    while (av[i])
    {
        unsortedVector.push_back(atoi(av[i]));
        i++;
    }

    sortedVector = unsortedVector;
}


void PmergeMe::sortVector()
{
    mergeSort(sortedVector.begin(), (sortedVector.end()));
}

void PmergeMe::executeVector()
{
    timerStart();
    argToVector();
    sortVector();
    timerEnd();
}

void PmergeMe::argToList()
{
    int i = 1;
    while (av[i])
    {
        unsortedList.push_back(atoi(av[i]));
        i++;
    }

    sortedList = unsortedList;
}

void PmergeMe::sortList()
{
    mergeSort(sortedList.begin(), (sortedList.end()));
}

void PmergeMe::executeList()
{
    timerStart();
    argToList();
    sortList();
    timerEnd();
}

void PmergeMe::timerStart()
{
    temp = clock();
}

void PmergeMe::timerEnd()
{
    if (temp == 0)
        return ;
    else
    {
        if (sortedVector.size() > 0)
            vectorSortTime = clock() - temp;
        else
            listSortTime = clock() - temp;
    }
}

void PmergeMe::execute()
{
    try {
        executeVector();
        executeList();
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << "\n";
        return ;
    }
    printResult();
}

void PmergeMe::printResult()
{
// Before: 141 79 526 321 [...]
// After: 79 141 321 526 [...]
// Time to process a range of 3000 elements with std::[..] : 62.14389 us
// Time to process a range of 3000 elements with std::[..] : 69.27212 us

    std::cout << "----------------------------------------\n";
    std::cout << "Vector: \n";
    std::cout << "Before: ";
    for (std::vector<int>::iterator it = unsortedVector.begin(); it != unsortedVector.end(); it++)
        std::cout << *it << " ";
    std::cout << "\n";

    std::cout << "After: ";
    for (std::vector<int>::iterator it = sortedVector.begin(); it != sortedVector.end(); it++)
        std::cout << *it << " ";
    std::cout << "\n";
    std::cout << "----------------------------------------\n";
    std::cout << "List: \n";
    std::cout << "Before: ";
    for (std::list<int>::iterator it = unsortedList.begin(); it != unsortedList.end(); it++)
        std::cout << *it << " ";
    std::cout << "\n";

    std::cout << "After: ";
    for (std::list<int>::iterator it = sortedList.begin(); it != sortedList.end(); it++)
        std::cout << *it << " ";
    std::cout << "\n";
    std::cout << "----------------------------------------\n";
    
    std::cout << "Time to process a range of " << unsortedVector.size() << " elements with std::vector : " << vectorSortTime << " us\n";

    std::cout << "Time to process a range of " << unsortedList.size() << " elements with std::list : " << listSortTime << " us\n";

}
