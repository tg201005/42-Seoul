#include "PmergeMe.hpp"
#include "PmergeMe.cpp"

//canonical
template <typename C>
PmergeMe<C>::PmergeMe(char **input, const char *containerName)
{
    //if length of input is 1, throw exception
    try {
        if (!input[1])
            throw std::invalid_argument("No argument");
        parseInput(input);
        this->containerName = containerName;
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
        exit(1);
    }
    depth = 0;
}

template <typename C>
PmergeMe<C>::~PmergeMe()
{
}

template <typename C>
PmergeMe<C>::PmergeMe(PmergeMe const& src)
{
    *this = src;
}

template <typename C>
PmergeMe<C>& PmergeMe<C>::operator=(PmergeMe const& src)
{
    if (this != &src)
    {
        this->_container = src._container;
    }
    return *this;
}

//member function
template <typename C>
void    PmergeMe<C>::execute()
{
    try {
       //time start
        clock_t start = clock();
        sort();
        clock_t end = clock();
        sorted_time = (end - start);
        print();
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
}

template <typename C>
void    PmergeMe<C>::parseInput(char** input)
{
    //check argument

    int i = 1;
    int temp;

    while (input[i])
    {
        std::stringstream ss;

        ss << input[i];
        ss >> temp;
        if (ss.fail() || !ss.eof())
            throw std::invalid_argument("Invalid argument");
        
        _container.push_back(temp);        

        //if input[i] is not positive integer and atoi is not working
        if (temp <= 0)
            throw std::invalid_argument("Invalid argument");
        
        i++;
    }

    _ori_container = _container;
}

template <typename C>
void    PmergeMe<C>::print()
{
    std::cout << "Before: ";
    for (typename C::iterator it = _ori_container.begin(); it != _ori_container.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;

    std::cout << "After: ";
    for (typename C::iterator it = _container.begin(); it != _container.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;

    std::cout << "Time to process a range of " << _container.size() << " elements with std::"<< containerName<< " : " << sorted_time << " us" << std::endl;

    std::cout << "----------------------------------------" << std::endl;
}

template <typename C>
void    PmergeMe<C>::sort()
{
    C indexes;
    
    recurSort(_container, indexes);
}

template <typename C>
void    PmergeMe<C>::rearrange(C& container, C& indexes)
{
    //print rearrange before

    if (DEBUG)
    {
        std::cout << "-----rearrange - s - :: depth: " << depth << "  --------------"<< std::endl;
        std::cout << "container: ";
        for (typename C::iterator it = container.begin(); it != container.end(); it++)
            std::cout << *it << " ";
        std::cout << std::endl;
        std::cout << "indexes: ";
        for (typename C::iterator it = indexes.begin(); it != indexes.end(); it++)
            std::cout << *it << " ";
        
        std::cout << std::endl;
        std::cout << "-----rearrange - s - :: depth: " << depth << "  --------------"<< std::endl;
    }

    C copyContainer = container;
    for (unsigned int i = 0; i < indexes.size(); i++)
    {
        container[i] = copyContainer[indexes[i]];
    }

    if (DEBUG)
    {
        std::cout << "-----rearrange - e - :: depth: " << depth << "  --------------"<< std::endl;
        std::cout << "container: ";
        for (typename C::iterator it = container.begin(); it != container.end(); it++)
            std::cout << *it << " ";
        std::cout << std::endl;
        std::cout << "indexes: ";
        for (typename C::iterator it = indexes.begin(); it != indexes.end(); it++)
            std::cout << *it << " ";
        
        std::cout << std::endl;
        std::cout << "-----rearrange - e - :: depth: " << depth << "  --------------"<< std::endl;
    }

    //using iterator function same
    return ;
}
    

//make the move iterator function
// argu of fuction is container iterator, num
//if nums is 0, return container iterator
//if nums is positive, return container iterator + nums
//if nums is negative, return container iterator - nums

template <typename C>
void    PmergeMe<C>::moveIter(typename C::iterator iter, int num)
{
    if (num == 0)
        return ;
    else if (num > 0)
    {
        for (int i = 0; i < num; i++)
            iter++;
    }
    else
    {
        num = -num;
        for (int i = 0; i < num; i++)
            iter--;
    }
    return ;
}

template <typename C>
void    PmergeMe<C>::binaryInsert(C& containerMain, C& containerPend, 
C& indexesMain, C& indexesPend)
{

    C   jacobsthal;
    unsigned int jacobPrev = 1;

    unsigned int insertSize;
    unsigned int stack = 0;
    typename C::iterator it;

    jacobsthal.push_back(1);

    //make jacobsthal sequence
    while((unsigned int)jacobsthal.back() < containerPend.size())
    {
        jacobsthal.push_back(jacobsthal.back() + 2 * jacobPrev);
        jacobPrev = *(jacobsthal.end() - 2);
    }

    for (unsigned int i = 0; i < jacobsthal.size(); i++)
    {
        if (jacobsthal[i] == 1)
            jacobPrev = 0;
        else 
            jacobPrev = jacobsthal[i - 1];

        for (unsigned int j = jacobsthal[i]; j > jacobPrev; j--)
        {

            // jacob = 3000, jacob prev = 1000 constainerPend size = 1500, 2999~1500 is not, 1499~1000 is used
            if (j > containerPend.size())
                continue;
                
            // adating first swap, and binary insert
            insertSize = std::min(j + stack, (unsigned int)containerMain.size() - 1);  
            
            // if (DEBUG)
            // {
            //     //j + stack, containerMain.size()
            //     std::cout << "j + stack: " << j + stack << std::endl;
            //     std::cout << "containerMain.size(): " << containerMain.size() << std::endl;

            //     //print arg of lower_bound
            //     //print containerMain.begin(), containerMain.begin() ->end
            //     std::cout <<"containerMain" << std::endl;
            //     for (typename C::iterator it = containerMain.begin(); it != containerMain.end(); it++)
            //         std::cout << *it << " ";
            //     std::cout << std::endl;


            //     std::cout << "containerMain.begin(): " << *containerMain.begin() << std::endl;
            //     std::cout << "containerMain.size(): " << containerMain.size() << std::endl;
            //     std::cout << "insertSize: " << insertSize << std::endl;
            //     std::cout << "containerMain.begin() + insertSize: " << *(containerMain.begin() + insertSize) << std::endl;
            //     std::cout << "containerPend[j - 1]: " << containerPend[j - 1] << std::endl;

            //     //print j, i, jacobsthal[i], jacobPrev
            //     std::cout << "i: " << i << std::endl;
            //     std::cout << "j: " << j << std::endl;

            // }

            //find the position to insert
            if (j == 1 )
                it = containerMain.begin();
            else
                it= std::lower_bound(containerMain.begin(), containerMain.begin() + insertSize, containerPend[j - 1]);

            if (!indexesMain.empty()) 
                //remember origin sequence
                indexesMain.insert(indexesMain.begin() + std::distance(containerMain.begin(), it), indexesPend[j - 1]);
            
            //insert the value
            containerMain.insert(it, containerPend[j - 1]);
            stack++;

        }
    }

    return ;
}

template <typename C>
void    PmergeMe<C>::recurSort(C& container, C& indexes)
{
    // end point

    if (DEBUG)
    {
        std::cout << "-----recur - s - :: depth: " << depth << "  --------------"<< std::endl;
        std::cout << "container: ";
        for (typename C::iterator it = container.begin(); it != container.end(); it++)
            std::cout << *it << " ";
        std::cout << std::endl;
        std::cout << "indexes: ";
        for (typename C::iterator it = indexes.begin(); it != indexes.end(); it++)
            std::cout << *it << " ";
        
        std::cout << std::endl;
        std::cout << "-----recur - s - :: depth: " << depth << "  --------------"<< std::endl;
    }    
        
    depth++;

    if (container.size() == 1)
        return ;

    typename C::iterator it1 = container.begin();
    typename C::iterator it2 = it1 + container.size() / 2;


    //it's the first time to call
    if (indexes.empty())
    {


        for (unsigned int j = 0; j < container.size() / 2; j++)
        {
            //for seperate container to main and pend. 
            //main is bigger than pend, main is left, pend is right
            if (*it1 < *it2)
                std::swap(*it1, *it2); 
            it1++;
            it2++;
        }
        
        C containerMain(container.begin(), container.begin() + container.size() / 2); 
        C containerPend(container.begin() + container.size() / 2, container.end());
        C indexesMain;
        C indexesPend;
      
        C subIndexes;

        for (unsigned int i = 0; i < containerMain.size(); i++)
            subIndexes.push_back(i);
        recurSort(containerMain, subIndexes);
        rearrange(containerPend, subIndexes);

        binaryInsert(containerMain, containerPend, indexesMain, indexesPend);

        container = containerMain;
        indexes = indexesMain;


    }
    else 
    {


        typename C::iterator itInd1;
        typename C::iterator itInd2;
        
        itInd1 = indexes.begin();
        itInd2 = indexes.begin() + container.size() / 2;

        for (unsigned int j = 0; j < container.size() / 2; j++)
        {
            if (*it1 < *it2)
            {
                std::iter_swap(it1, it2);
                std::iter_swap(itInd1, itInd2);
            }

            it1++;
            it2++;

            itInd1++;
            itInd2++;
        } 

        C containerMain(container.begin(), container.begin() + container.size() / 2);
        C containerPend(container.begin() + container.size() / 2, container.end());
        C indexesMain;
        C indexesPend;

        indexesMain.insert(indexesMain.end(), indexes.begin(), indexes.begin() + container.size() / 2);
        indexesPend.insert(indexesPend.end(), indexes.begin() + container.size() / 2, indexes.end());

        C subIndexes;
        for (unsigned int i = 0; i < containerMain.size(); i++)
            subIndexes.push_back(i);
        
        recurSort(containerMain, subIndexes);

        rearrange(containerPend, subIndexes);
        rearrange(indexesMain, subIndexes);
        rearrange(indexesPend, subIndexes);

        binaryInsert(containerMain, containerPend, indexesMain, indexesPend);
        container = containerMain;
        indexes = indexesMain;

    }


    return ;
}