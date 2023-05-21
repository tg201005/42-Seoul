//- 하나의 정수에 4자리의 십진수를 기억하는 길이가 20인 정수 배열을 이용하여 80자리의 수를 처리하고자 한다. 이 배열에 1000 이하의 정수 n을 곱하는 함수 void Multiply(int number[], int n)을 작성하시오. 단 이 함수를 호출하면 각 배열의 원소에는 0-9999의 값이 저장되어야 합니다. 이 함수를 이용하여 50! 값을 출력하는 프로그램을 작성하시오. 맨 앞에 연속되는 필요 없는 0은 제거하시오.
//(Ex. 30414093201713378043612608166064768844377641568960512000000000000)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Multiply(int number[], int n);
void Print(int number[]);
void RemoveZero(int number[]);
void Reverse(int number[]);
void Add(int number[], int n);

int main(void)
{
    int number[20] = { 0 };
    int i;

    number[0] = 1;
    for (i = 1; i <= 50; i++)
        Multiply(number, i);

    RemoveZero(number);
    Reverse(number);
    Print(number);

    return 0;
}

void Multiply(int number[], int n)
{
    int i;

    for (i = 0; i < 20; i++)
        number[i] *= n;
    for (i = 0; i < 20; i++)
        if (number[i] >= 10000)
        {
            number[i + 1] += number[i] / 10000;
            number[i] %= 10000;
        }
}

void Print(int number[])
{
    int i;

    for (i = 19; i >= 0; i--)
        printf("%04d", number[i]);
    printf("\n");
}

void RemoveZero(int number[])
{
    int i;

    for (i = 19; i >= 0; i--)
        if (number[i] != 0)
            break;
    for (; i >= 0; i--)
        printf("%04d", number[i]);
    printf("\n");
}

void Reverse(int number[])
{
    int i, temp;

    for (i = 0; i < 10; i++)
    {
        temp = number[i];
        number[i] = number[19 - i];
        number[19 - i] = temp;
    }
}

void Add(int number[], int n)
{
    int i;

    for (i = 0; i < 20; i++)
        number[i] += n;
    for (i = 0; i < 20; i++)
        if (number[i] >= 10000)
        {
            number[i + 1] += number[i] / 10000;
            number[i] %= 10000;
        }
}
