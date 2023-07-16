#include "easyfind.hpp"

int main() {
    std::vector<int> v;
    int search = 3;

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

