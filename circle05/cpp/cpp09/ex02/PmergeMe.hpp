#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <list>
#include <map>
#include <ctime>


template <typename Container>
class PmergeContainer
{
    private:
        //canonical form
        PmergeContainer(const PmergeContainer &copy);
        PmergeContainer &operator=(const PmergeContainer &copy);

        //data
        char **av;
        int depth;
  
        Container unsortedContainer;
        Container mainContainer;
        Container subContainer;
        Container sortedContainer;
        
        void argToContainer();
        void sortContainer();
        void executeContainer();

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
}

class PmergeMe
{
    private:
        //canonical form
        PmergeMe(const PmergeMe &copy);
        PmergeMe &operator=(const PmergeMe &copy);

        //data
        char **av;
        int depth;


        //vector
    
        std::vector<int> unsortedVector;
        std::vector<int> mainVector;
        std::vector<int> subVector;
        std::vector<int> sortedVector;
        
        void argToVector();
        void sortVector();
        void executeVector();

        //list
        
        std::list<int> unsortedList;
        std::list<int> mainList;
        std::list<int> subList;
        std::list<int> sortedList;
        
        void argToList();
        void sortList();
        void executeList();

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
        clock_t vectorSortTime;
        clock_t listSortTime;
        
        void timerStart();
        void timerEnd();



    public:
        //constructor & destructor
        PmergeMe(char **av);
        ~PmergeMe();

        //execute
        void execute();
        void printResult();
};

