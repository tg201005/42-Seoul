#include <iostream>
#include <cstdlib>
#include <new>
#include <unistd.h>

void checkMemoryLeaks() {
    // 메모리 누수 검사
   
}

int main() {
    // atexit를 사용하여 checkMemoryLeaks 함수 등록
    atexit(checkMemoryLeaks);

    // 메모리 누수 예시
    int* num = new int;
    
    // 프로그램 종료 시 메모리 해제하지 않음
    system("leaks a.out");
    while (1);
    return 0;
}