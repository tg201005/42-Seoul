#include "Span.hpp"
#include <algorithm>

Span::Span(unsigned int N) : N(N) {}

Span::Span() {}

Span::Span(const Span &sp) {
    *this = sp;
}

Span& Span::operator=(const Span &sp) {
    if (this != &sp) {
        this->N = sp.N;
        this->data = sp.data;
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
        throw std::invalid_argument("Not enough data");
    }
    
    std::sort(data.begin(), data.end());
    int shortest;

    for (unsigned int i = 1; i < data.size(); ++i) {
        int span = data[i] - data[i - 1];
        if (i == 1)
            shortest = span;
        else {
            if (span < shortest) {
            shortest = span;
        }
        }
    }    
    
    return shortest;
}

int Span::longestSpan() {
    if (data.size() < 2) {
        throw std::invalid_argument("Not enough data");
    }
    std::sort(data.begin(), data.end());
    return data[data.size() - 1] - data[0];
}

void Span::print() {
    for (unsigned int i = 0; i < data.size(); ++i) {
        std::cout << data[i] << " ";
    }
    std::cout << std::endl;
}