#include "PmergeMe.hpp"


template <typename Container>
PmergeMe<Container>::PmergeMe(char **av)
{
    this->av = av;
    depth = 0;
}

template <typename Container>
PmergeMe<Container>::~PmergeMe()
{
}

template <typename Container>
PmergeMe<Container>::PmergeMe(const PmergeMe &copy)
{
    *this = copy;
}   

template <typename Container>
PmergeMe<Container> &PmergeMe<Container>::operator=(const PmergeMe &copy)
{
    if (this == &copy)
        return *this;
    return *this;
}

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


template <typename Container>
template <typename T>
void PmergeMe<Container>::mergeSort(T begin, T end)
{
    
    if (begin == end)
        return ;

    // depth++;
    // printIterator(begin, end);
    // std::cout << "depth: " << depth << "\n"; //depth: 0

    T mid = begin;
    int length = lengthIterator(begin, end);
    moveIterator(mid, length / 2); 

    T temp = mid;
    temp ++;

    mergeSort(begin, mid);
    mergeSort(temp, end);
    Merge(begin, mid, end);
}

template <typename Container>
template <typename T>
void PmergeMe<Container>::swapValue(T &mainIt1, T &mainIt2){
    int len1 = lengthIterator(mainContainer.begin(), mainIt1);
    int len2 = lengthIterator(mainContainer.begin(), mainIt2);

    T subIt1 = subContainer.begin();
    T subIt2 = subContainer.begin();
    
    moveIterator(subIt1, len1);
    moveIterator(subIt2, len2);

    int temp1 = *mainIt1;
    *mainIt1 = *mainIt2;
    *mainIt2 = temp1;

    int temp2 = *subIt1;
    *subIt1 = *subIt2;
    *subIt2 = temp2;
}

template <typename Container>
template <typename T>
void PmergeMe<Container>::Merge(T begin, T mid, T end)
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

template <typename Container>
void PmergeMe<Container>::argToContainer()
{
    int i = 1;
    int temp;

    while (av[i])
    {
        std::stringstream ss(av[i]);
        ss >> temp;
        if (ss.fail())
            throw std::invalid_argument("invalid argument");
        if (ss.eof() == false)
            throw std::invalid_argument("invalid argument");
        unsortedContainer.push_back(temp);
        i++;
    }

    typename Container::iterator begin = unsortedContainer.begin();
    typename Container::iterator end = unsortedContainer.end();
    typename Container::iterator current = begin;

    // i want to fill mainContainer and subContainer with unsortedContainer
    // in every case, 처음부터 시작해서 current와 current + 1을 비교한다. 
    // 만약 current가 current + 1보다 크다면, mainContainer에 current를 넣는다. current + 1은 subContainer에 넣는다.
    // 만약 current가 current + 1보다 작다면, subContainer에 current를 넣는다. current + 1은 mainContainer에 넣는다.
    // if the size of unsortedContainer is 홀수, last elem of unsortedContainer will be a last elem of subContainer

    while (current != end)
    {
        typename Container::iterator next = current;
        ++next;
        if (next == end)
        {
            subContainer.push_back(*current);
            break;
        }
        if (*current > *next)
        {
            mainContainer.push_back(*current);
            subContainer.push_back(*next);
        }
        else
        {
            subContainer.push_back(*current);
            mainContainer.push_back(*next);
        }
        current = next;
        ++current;
    }
}

template <typename Container>
void PmergeMe<Container>::sortMainContainer()
{
    mergeSort(mainContainer.begin(), mainContainer.end());
}


template <typename Container>
void PmergeMe<Container>::binarySearch(int value, int length)
{
    typename Container::iterator begin = mainContainer.begin();
    typename Container::iterator end = mainContainer.end();
    typename Container::iterator mid = begin;

    while (1)
    {
        printContainer();
        length = length / 2;
        std::cout << "value: " << value << "\n";
        std::cout << "length: " << length << "\n";  
        moveIterator(mid, length);
        if (length == 0)
            break;
        if (*mid == value)
        {
            throw std::invalid_argument("invalid argument");
        }
        else if (*mid > value)
        {
            // begin = begin;
            end = mid;
            mid = begin;
        }
        else
        {
            begin = mid;
            // end = end;
            // mid = mid;
        }

    }
    
    //insert value to mainContainer at the position of begin

    mainContainer.insert(++begin, value);
}



template <typename Container>
void PmergeMe<Container>::fillJacobVector(std::vector<int> &jacobVector)
{
    int t_[] = {0, 1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461, 10923,
                21845, 43691, 87381, 174763, 349525, 699051, 1398101, 2796203,
                5592405, 11184811, 22369621, 44739243, 89478485, 178956971,
                357913941, 715827883, INT_MAX};

    int size = sizeof(t_) / sizeof(t_[0]);

    for (int i = 0; i < size; ++i) {
        jacobVector.push_back(t_[i]);
    }
}


template <typename Container>
void PmergeMe<Container>::sortSubContainer()
{
    // subcontaine의 첫 번째 요소를 mainContainer에 맨 앞에 삽입한다.
    typename Container::iterator mainIt = mainContainer.begin();
    typename Container::iterator subIt = subContainer.begin();

    //insert value of subIt to mainContainer front

    //subContainer의 첫 번째 요소를 mainContainer에 맨 앞에 삽입한다.
    mainContainer.insert(mainIt, *subIt);

    std::vector <int> jacobVector;
    fillJacobVector(jacobVector);



    int start = 0;
    int end = -1;
    int k = 0;
    int added = 0;
    while (1)
    {
        int value;
        if (jacobVector[k + 1] >= (int)subContainer.size() && jacobVector[k] < (int)subContainer.size())
            start = (int)subContainer.size();
        else
            start = jacobVector[k + 1];
        end = jacobVector[k];        

        while (start != end )
        {
            subIt = subContainer.begin();
            moveIterator(subIt, start);
            value = *subIt;
            binarySearch(value, (int)mainContainer.size() + added);
            start --;    
            added++;
         
        }
        if( jacobVector[k + 1] >= (int)subContainer.size())
            break;
        k++;
    }
}

template <typename Container>
void PmergeMe<Container>::executeContainer()
{
    timerStart();
    argToContainer();
    sortMainContainer();
    sortSubContainer();
    printContainer();
    timerEnd();

}


template <typename Container>   
void PmergeMe<Container>::timerStart()
{
    temp = clock();
}


template <typename Container>
void PmergeMe<Container>::timerEnd()
{
    if (temp == 0)
        return ;
    else
    {
        sortTime = clock() - temp;
    }
}

template <typename Container>
void PmergeMe<Container>::printResult(const std::string &containerName)
{
    std::cout << "Before: ";
    for (typename Container::iterator it = unsortedContainer.begin(); it != unsortedContainer.end(); it++)
        std::cout << *it << " ";
    std::cout << "\n";

    std::cout << "After: ";
    for (typename Container::iterator it = sortedContainer.begin(); it != sortedContainer.end(); it++)
        std::cout << *it << " ";
    std::cout << "\n";

    std::cout << "Time to process a range of " << unsortedContainer.size() << " elements with std::" << containerName << " -- " << sortTime << " us\n";

}

template <typename Container>
void PmergeMe<Container>::printContainer()
{
    std::cout << "unsortedContainer: ";
    for (typename Container::iterator it = unsortedContainer.begin(); it != unsortedContainer.end(); it++)
        std::cout << *it << " ";
    std::cout << "\n";

    std::cout << "mainContainer: /";
    for (typename Container::iterator it = mainContainer.begin(); it != mainContainer.end(); it++)
        std::cout << *it << " / ";
    std::cout << "\n";

    std::cout << " subContainer: ";
    for (typename Container::iterator it = subContainer.begin(); it != subContainer.end(); it++)
        std::cout << *it << " / ";
    std::cout << "\n";
}

template <typename Container>
void PmergeMe<Container>::execute()
{
    try {
        executeContainer();
    }
    catch (std::exception &e){
        std::cout << e.what() << std::endl;
    }
}