#include <iostream>
#include <vector>
#include <algorithm>

template <typename T>
typename T::iterator easyfind(T &container, int n) {
    typename T::iterator it;

    it = std::find(container.begin(), container.end(), n);
    if (it == container.end()) {
        throw std::exception();
    }
    return it;
}

int main() {
    std::vector<int> v;
    int search = 11;

    for (int i = 0; i < 10; i++) {
        v.push_back(i);
    }

    try {
        std::cout << "Found " << search << " at index " << easyfind(v, search) - v.begin() << '\n';
    } catch (const std::exception &e) {
        std::cout << search << " not found in the container\n";
    }

    return 0;
}

