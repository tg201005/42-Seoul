#ifndef MUTANTSTACK_HPP_
#define MUTANTSTACK_HPP_

#include <stack>
#include <deque>
#include <iostream>


template <typename T>
class MutantStack : public std::stack<T> {
    
    private:

    
    public:
        MutantStack();
        MutantStack(const MutantStack &ms);
        MutantStack &operator=(const MutantStack &ms);
        ~MutantStack();

        typedef typename std::deque<T>::iterator iterator;
        iterator end();
        iterator begin();

        void print(); 
};

#include "MutantStack.tpp"

#endif