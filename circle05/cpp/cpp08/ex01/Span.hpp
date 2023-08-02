#ifndef SPAN_HPP
# define SPAN_HPP


#include <vector>
#include <stdexcept>

class Span {
    unsigned int N;
    std::vector<int> data;

    public:
        Span(unsigned int N);
        Span(const Span &src);
        Span &operator=(const Span &rhs);
        ~Span();

        void addNumber(int num);

        int shortestSpan();
        int longestSpan();

    private:
        Span();


};

#endif