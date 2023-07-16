#include "Span.hpp"
#include <algorithm>

Span::Span(unsigned int N) : N(N) {}

Span::Span() {}

Span::Span(const Span &src) {
    *this = src;
}

Span& Span::operator=(const Span &rhs) {
    if (this != &rhs) {
        this->N = rhs.N;
        this->data = rhs.data 
    }
    return *this;
}

Span::~Span() {}



void Span::addNumber(int num) {
    if (data.size() >= N) {
        throw std::out_of_range("Span is full");
    }
    data.push_back(num);
}


int Span::shortestSpan() {
    if (data.size() < 2) {
        throw std::invalid_argument("Not enough data in Span");
    }
    std::sort(data.begin(), data.end());
    int shortest = data[1] - data[0];
    for (unsigned int i = 2; i < data.size(); ++i) {
        int span = data[i] - data[i - 1];
        if (span < shortest) {
            shortest = span;
        }
    }    
    return shortest;
}

int Span::longestSpan() {
    if (data.size() < 2) {
        throw std::invalid_argument("Not enough data in Span");
    }
    int minElem = *std::min_element(data.begin(), data.end());
    int maxElem = *std::max_element(data.begin(), data.end());

    return maxElem - minElem;
}
