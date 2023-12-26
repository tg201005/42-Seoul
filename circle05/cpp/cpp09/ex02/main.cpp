#include "PmergeMe.hpp"

int main(int ac, char **av)
{
    (void) ac;
    PmergeMe<std::deque<int> > d(av, "deque");
    d.execute();
    PmergeMe<std::vector<int> > v(av, "vector");
    v.execute();
    
}