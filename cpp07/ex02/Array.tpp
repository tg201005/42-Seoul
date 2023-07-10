#ifndef ARRAY_TPP
# define ARRAY_TPP


#include <iostream>
#include <exception>

template <typename T>
Array<T>::Array(void) : _size(0), _array(NULL) {}

template <typename T>
Array<T>::Array(unsigned int n) : _size(n){

    _array = new T[n];
    std::cout << "Array of " << *_array << " created" << std::endl;
    std::cout << "Array of " << _array << " created" << std::endl;
}

template <typename T>
Array<T>::Array(Array const & other) : _size(other._size){
    _array = new T[other._size];
    for (unsigned int i = 0; i < other._size; i++) {
        _array[i] = other._array[i];
    }
}

template <typename T>
Array<T>::~Array(void) {
    if (_array)
        delete [] _array;
}

template <typename T>
Array<T> & Array<T>::operator=(Array const & other) {
    if (this != &other) {
        delete [] _array;
        _size = other._size;
        _array = new T[other._size];
        for (unsigned int i = 0; i < other._size; i++) {
            _array[i] = other._array[i];
        }
    }
    return *this;
}

template <typename T>
T & Array<T>::operator[](unsigned int i) {
    if (i >= _size) {
        throw std::exception();
    }
    return _array[i];
}

template <typename T>
unsigned int Array<T>::size(void) const {
    return _size;
}
#endif