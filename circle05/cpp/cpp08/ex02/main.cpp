#include "MutantStack.hpp"
#include <stack>
#include <list>


// int main()
// {
//     {        
//         MutantStack<int> mstack;
//         mstack.push(5);
//         mstack.push(17);

//         std::cout << "---------------------" << std::endl;
//         std::cout << "MutantStack" << std::endl;
//         std::cout << "---------------------" << std::endl;
        
//         std::cout << "Top : " << mstack.top() << std::endl;
        
//         mstack.pop();
//         std::cout << "Size : " << mstack.size() << std::endl;
//         mstack.push(3);
//         mstack.push(5);
//         mstack.push(737);
//         //[...]
//         mstack.push(0);
//         MutantStack<int>::iterator it = mstack.begin();
//         MutantStack<int>::iterator ite = mstack.end();
//         ++it;
//         --it;

//         std::cout << "---------------------" << std::endl;
//         while (it != ite)
//         {
//         std::cout << *it << std::endl;
//         ++it;
//         }

//         std::stack<int> s(mstack);
//     }



//     {
//         std::cout << "---------------------" << std::endl;
//         std::cout << "list" << std::endl;
//         std::cout << "---------------------" << std::endl;
        
//         std::list<int> list;
//         list.push_back(5);
//         list.push_back(17);
        
//         std::cout << "Top : " << list.back() << std::endl; 
//         list.pop_back();

//         std::cout << "Size : " << list.size() << std::endl;

//         list.push_back(3);
//         list.push_back(5);
//         list.push_back(737);
//         //[...]
//         list.push_back(0);
//         std::list<int>::iterator it = list.begin();
//         std::list<int>::iterator ite = list.end();
//         ++it;
//         --it;

//         std::cout << "---------------------" << std::endl;

//         while (it != ite)
//         {
//             std::cout << *it << std::endl;
//         ++it;
//         }
//     }

//     std::cout << "---------------------" << std::endl;

//     return 0;
// }



int main(){
    MutantStack<int> mstack;
    mstack.push(1);
    mstack.push(2);
    mstack.push(3);
    mstack.push(4);
    mstack.push(5);
    mstack.push(6);
    mstack.push(7);
    mstack.push(8);
    mstack.push(9);

    std::cout << "---------------------" << std::endl;
    std::cout << "MutantStack" << std::endl;
    std::cout << "---------------------" << std::endl;
    
    std::cout << "Top : " << mstack.top() << std::endl;
    
    mstack.pop();
    mstack.pop();
    mstack.pop();
    std::cout << "Size : " << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();

    std::cout << "---------------------" << std::endl;


    std::cout << "---------------------" << std::endl;
    std::cout << "MutantStack" << std::endl;
    mstack.print();
    std::cout << "---------------------" << std::endl;
    
    MutantStack<int> mstack2(mstack);
    std::cout << "MutantStack2" << std::endl;
    mstack2.print();
    std::cout << "---------------------" << std::endl;

}