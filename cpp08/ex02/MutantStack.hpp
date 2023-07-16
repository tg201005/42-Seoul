#ifndef MUTANTSTACK_HPP_
#define MUTANTSTACK_HPP_

#include <deque>

template <typename T>
class MutantStack : public std::deque<T> {

    public:
        void push(const T& val);
        void pop();
        T& top();
        const T& top() const;
        typename std::deque<T>::size_type size() const;
};

#include "MutantStack.tpp"

#endif