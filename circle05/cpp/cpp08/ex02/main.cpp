#include "MutantStack.hpp"
#include <stack>
#include <list>


int main()
{
        MutantStack<int> mstack;
        mstack.push(5);
        mstack.push(17);

        std::cout << "---------------------" << std::endl;
        std::cout << "MutantStack" << std::endl;
        std::cout << "---------------------" << std::endl;
        
        std::cout << "Top : " << mstack.top() << std::endl;
        
        mstack.pop();
        std::cout << "Size : " << mstack.size() << std::endl;
        mstack.push(3);
        mstack.push(5);
        mstack.push(737);
        //[...]
        mstack.push(0);
        MutantStack<int>::iterator it = mstack.begin();
        MutantStack<int>::iterator ite = mstack.end();
        ++it;
        --it;

        std::cout << "---------------------" << std::endl;
        while (it != ite)
        {
        std::cout << *it << std::endl;
        ++it;
        }

        std::stack<int> s(mstack);
    

        std::cout << "---------------------" << std::endl; 
        

        MutantStack<int> mstack2(mstack);
        std::cout << "MutantStack2" << std::endl;
        mstack2.print();
        std::cout << "---------------------" << std::endl;

    


    std::cout << "---------------------" << std::endl;

    return 0;
}
