#include "PmergeMe.hpp"

// std::vector <long long> origin;
// void  Merge(vector<int> &arr, int low, int high, int depth){
//     int mid = low + (high - low)/2;
//     int n1 = mid - low + 1;
//     int n2 = high - mid;

//     vector<long long> leftArr(n1);
//     vector<long long> rightArr(n1);
//     //low ~ mid 까지의 배열과 mid + 1~ high 까지의 배열을 차례로 조합해서 정렬한다. 
//     for(int i = 0; i < n1; i++)
//         leftArr[i] = arr[low + i];
//     for(int i = 0; i < n1; i++)
//         rightArr[i] = arr[mid + 1 + i];
//     int i = 0;
//     int j = 0;
//     int k = low;

//     while(i < n1 && j < n2){
//         if(leftArr[i] <= rightArr[j]){
//             arr[k] = leftArr[i];
//             i++;
//         }
//         else{
//             arr[k] = rightArr[j];
//             j++;
//         }
//         k++;
//     }

//     while(i < n1){
//         arr[k++] = leftArr[i++];
//     }
//     while(j < n2){
//         arr[k++] = rightArr[j++];
//     }

// }

// void mergeSort(vector<int> &arr, int low, int high, int depth){
//     // std::cout << "mergesort " << low << " " << high << "\n";

//     if (low < high){
//         int mid = low + (high - low)/2;
//         mergeSort(arr, low, mid, depth +1);
//         mergeSort(arr, mid +1, high, depth + 1);
//         Merge(arr, low, high, depth + 1);
//     }  
// }

// void 

// int main(int ac, char **av)
// {

//     //char **av to map (key is start from 0, value is int (av[i]))
    
//     std::map<int, int> orderAndValue;

//     std::vector<int> v;
//     for(int i = 1; i < ac; i++){
//         v.push_back(atoi(av[i]));
//     }

//     //mergeSort
//     mergeSort(v, 0, v.size() - 1, 0);

// }

int main(int ac, char **av)
{
    (void) ac;
    
    PmergeMe p(av);
    p.execute();
    return 0;
}