#ifndef SPAN_HPP
# define SPAN_HPP


#include <vector>
#include <stdexcept>
#include <iostream>

class Span {


    public:
        Span(unsigned int N);
        Span(const Span &sp);
        Span &operator=(const Span &sp);
        ~Span();

        void addNumber(int num);

        int shortestSpan();
        int longestSpan();

        void print();
        
    private:
        Span();
        
        unsigned int N;
        std::vector<int> data;

};

#endif