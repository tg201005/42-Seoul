#pragma once

#include <exception>
#include <iostream>

template <class T>
class Array {
    
    private:
        T *_array;
        unsigned int _size;
    
    public:
        Array();
        Array(unsigned int n);
        Array(Array const &other);
        ~Array();
        Array &operator=(Array const &other);
        T &operator[](unsigned int i);
        unsigned int size() const;

        class OutOfRangeException : public std::exception {
            public:
                virtual const char *what() const throw();
        };
};

#include "Array.tpp"