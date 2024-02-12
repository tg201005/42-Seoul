#include "PmergeMe.hpp"

int main(int ac, char **av)
{
    try {
        (void) ac;
        PmergeMe<std::deque<int> > d(av, "deque");
        d.execute();
        PmergeMe<std::vector<int> > v(av, "vector");
        v.execute();
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    
}