#ifndef MUTANTSTACK_TPP
#define MUTANTSTACK_TPP

template <typename T>
void MutantStack<T>::push(const T& val) {
    std::deque<T>::push_back(val);
}

template <typename T>
void MutantStack<T>::pop() {
    std::deque<T>::pop_back();
}

template <typename T>
T& MutantStack<T>::top() {
    return std::deque<T>::back();
}

template <typename T>
typename std::deque<T>::size_type MutantStack<T>::size() {
    return std::deque<T>::size();
}

#endif