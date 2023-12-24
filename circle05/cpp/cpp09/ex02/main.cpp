#include "PmergeMe.hpp"

// // std::vector <long long> origin;
// // void  Merge(vector<int> &arr, int low, int high, int depth){
// //     int mid = low + (high - low)/2;
// //     int n1 = mid - low + 1;
// //     int n2 = high - mid;

// //     vector<long long> leftArr(n1);
// //     vector<long long> rightArr(n1);
// //     //low ~ mid 까지의 배열과 mid + 1~ high 까지의 배열을 차례로 조합해서 정렬한다. 
// //     for(int i = 0; i < n1; i++)
// //         leftArr[i] = arr[low + i];
// //     for(int i = 0; i < n1; i++)
// //         rightArr[i] = arr[mid + 1 + i];
// //     int i = 0;
// //     int j = 0;
// //     int k = low;

// //     while(i < n1 && j < n2){
// //         if(leftArr[i] <= rightArr[j]){
// //             arr[k] = leftArr[i];
// //             i++;
// //         }
// //         else{
// //             arr[k] = rightArr[j];
// //             j++;
// //         }
// //         k++;
// //     }

// //     while(i < n1){
// //         arr[k++] = leftArr[i++];
// //     }
// //     while(j < n2){
// //         arr[k++] = rightArr[j++];
// //     }

// // }

// // void mergeSort(vector<int> &arr, int low, int high, int depth){
// //     // std::cout << "mergesort " << low << " " << high << "\n";

// //     if (low < high){
// //         int mid = low + (high - low)/2;
// //         mergeSort(arr, low, mid, depth +1);
// //         mergeSort(arr, mid +1, high, depth + 1);
// //         Merge(arr, low, high, depth + 1);
// //     }  
// // }

// // void 

// // int main(int ac, char **av)
// // {

// //     //char **av to map (key is start from 0, value is int (av[i]))
    
// //     std::map<int, int> orderAndValue;

// //     std::vector<int> v;
// //     for(int i = 1; i < ac; i++){
// //         v.push_back(atoi(av[i]));
// //     }

// //     //mergeSort
// //     mergeSort(v, 0, v.size() - 1, 0);

// // }

// int main(int ac, char **av)
// {
//     (void) ac;

//     try {
//         if (ac < 2)
//             throw std::invalid_argument("No argument");
        
//         PmergeMe<std::vector<int> > v(av);
//         v.execute();
//         v.printResult("vector");

//         PmergeMe<std::deque<int> > d(av);
//         d.execute();
//         d.printResult("deque");
//     }
//     catch (std::exception& e) {
//         std::cout << e.what() << std::endl;
//         return 0;
//     }
    
// }

// #include <vector>
// #include <unordered_map>
// #include <algorithm>
// #include <iostream>


// int cmp_func(int a, int b) {
//     if (a < b) return -1;
//     if (a > b) return 1;
//     return 0;
// }

// int find_insert_point(int x, std::vector<int>& xs, int(*cmp)(int, int)) {
//     int lo = 0;
//     int hi = xs.size();
//     while (hi > lo) {
//         int mid = lo + (hi - lo) / 2;

//         // std::cout << "vector: ";
//         // for(size_t i = 0; i < xs.size(); i++) {
//         //     std::cout << xs[i] << " ";
//         // }
//         // std::cout << "\n";
//         // std::cout << "hi: " << hi << " lo: " << " x : " << x << " xs[mid]: " << xs[mid] << " mid: " << mid << "\n";
//         int cmp_result = cmp(x, xs[mid]);
//         if (cmp_result == 0) return mid;
//         if (cmp_result < 0) hi = mid;
//         if (cmp_result > 0) lo = mid + 1;
//     }
//     return lo;
// }

// void sort_func(std::vector<int>& xs, int(*cmp)(int, int), int depth) {
//     std::cout << "hi 1, depth is " << depth << "-------\n";
//     if (xs.size() < 2) {
//         return;
//     }

//     std::unordered_map<int, std::vector<int> > partner;
//     int half = xs.size() / 2;
//     for (int i = 0; i < half; ++i) {
//         if (cmp(xs[i], xs[i + half]) < 0) {
//             std::swap(xs[i], xs[i + half]);
//         }
//         partner[xs[i]].push_back(xs[i + half]);
//     }

//     std::vector<int> first_half(xs.begin(), xs.begin() + half);
//     sort_func(first_half, cmp, depth + 1);
//     std::cout << "hi 2, depth is " << depth << "-------\n";

//     for (int i = 0; i < half; ++i) {
//         //i, half
//         std::cout << "i is " << i << " half is " << half << "\n";
//         std::cout << "hi 2.0, depth is " << depth << "-------\n";
//         //if (partner[xs[2 * i]].empty()) break;
//         if (partner[xs[2 * i]].empty()) continue;
        
//         int y = partner[xs[2 * i]].back();
//         std::cout << "hi 2.1, depth is " << depth << "-------\n";
//         partner[xs[2 * i]].pop_back();
//         std::cout << "hi 2.2, depth is " << depth << "-------\n";
//         int idx = find_insert_point(y, first_half, cmp);
//         std::cout << "hi 2.3, depth is " << depth << "-------\n";

//         //cout idx, i,
//         std::cout << "---depth: " << depth << "---\n";
//         std::cout << "idx: " << idx << " i: " << i << "y: " << y << "\n" << "half: " << half << "\n";
//         std::cout << "------------------\n";
//         //arg of rotate: first, last, new_las
//         std::rotate(first_half.begin() + idx, first_half.end() - 1, first_half.end());
//         first_half[idx] = y;
//         std::cout << "hi 2.5, depth is " << depth << "-------\n";
//     }
//     std::cout << "hi 3, depth is " << depth << "-------\n";
    
//     // std::copy(first_half.begin(), first_half.end(), xs.begin());

//     //print all the partner <key, value>

//     for (auto it = partner.begin(); it != partner.end(); ++it) {
//         std::cout << it->first << " : ";
//         for (size_t i = 0; i < it->second.size(); ++i) {
//             std::cout << it->second[i] << " ";
//         }
//         std::cout << "\n";
//     }

//     if (xs.size() % 2 > 0) {
//         int i = xs.size() - 1;
//         int idx = find_insert_point(xs[i], first_half, cmp);
//         std::rotate(first_half.begin() + idx, first_half.end() - 1, first_half.end());
//         //   xs[i] = first_half.back();
//     }
// }

// int main() {
//     std::vector<int> xs;
//     xs.push_back(3);
//     xs.push_back(5);
//     xs.push_back(1);
//     xs.push_back(2);
//     xs.push_back(4);

//     sort_func(xs, cmp_func, 0);
//     for(size_t i = 0; i < xs.size(); i++) {
//         std::cout << xs[i] << " ";
//     }

//     return 0;
// }


