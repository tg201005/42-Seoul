#include <iostream>
#include <sstream>
#include <string> 
#include <iostream> 

// int main() 
// {
//     std::stringstream ss;

//     // 문자열 추가
//     ss << "Hello, ";
//     ss << "13";
    
//     // 문자열 출력
//     int i;
//     ss >> i;
//     std::cout << i << std::endl;
//     std::cout << ss.str() << std::endl;

//     // stringstream 비우기
//     ss.str("");  // 또는 ss.str(std::string())로도 가능

//     // 다른 타입의 데이터 추가
//     int number = 123;
//     float value = 3.14;
//     ss << "Number: " << number << ", Value: " << value;

//     // 다시 문자열 출력
//     std::cout << ss.str() << std::endl;

//     return 0;
// }

#include <iostream>
#include <string>
#include <sstream>
using namespace std;
 
 int main() {
    string str1 = "1D2S#10S";
    string str2 = "1111DAWV2S#10S";
     
    istringstream iss1(str1);
    istringstream iss2(str2);
    int num1, num2;
    while (iss1 >> num1) cout << num1 << " ";
    cout << endl;
    while (iss2 >> num2) cout << num2 << " ";
    cout << endl;
    
    istringstream iss3(str1);
    istringstream iss4(str2);
    char ch1, ch2;
    while (iss3 >> ch1) cout << ch1 << " ";
    cout << endl;
    while (iss4 >> ch2) cout << ch2 << " ";
    cout << endl;
}