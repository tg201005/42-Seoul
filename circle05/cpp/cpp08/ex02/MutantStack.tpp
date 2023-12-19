#ifndef MUTANTSTACK_TPP
#define MUTANTSTACK_TPP

#include "MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack() {}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack &ms) {
    *this = ms;
}

template <typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack &ms) {
    if (this != &ms) {
        this->c = ms.c;
    }
    return *this;
}

template <typename T>
MutantStack<T>::~MutantStack() {}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin() {
    return this->c.begin();
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end() {
    return this->c.end();
}

//print msstack

template <typename T>
void MutantStack<T>::print() {
    typename MutantStack<T>::iterator it = this->begin();
    typename MutantStack<T>::iterator ite = this->end();

    while (it != ite) {
        std::cout << *it << std::endl;
        ++it;
    }
}

#endif