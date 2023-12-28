#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <list>
#include <cstdlib>
#include <sstream>



#define DEBUG 0

template <typename C>
class PmergeMe
{
    public:
        void parseInput(char** input);

        PmergeMe(char **input, const char *containerName);
        ~PmergeMe();
        PmergeMe(PmergeMe const& src);
        PmergeMe& operator=(PmergeMe const& src);

        
        void	print();
        void    execute(); 

    private:        
        void    moveIter(typename C::iterator iter, int num);

        void	sort();
        void	recurSort(C& vec, C& indexes);
        void	rearrange(C& vec, C& indexes);
        void	binaryInsert(C& vecMain, C& vecPend, C& indMain, C& indPend);
        
        int     depth;

        //Container
        C _container;
        C _ori_container;
        std::string containerName;

        clock_t sorted_time;        

};

#include "PmergeMe.tpp"

template class PmergeMe<std::deque<int> >;
template class PmergeMe<std::vector<int> >;

#endif