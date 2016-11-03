#include <stdio.h>

// 함수포인터 타입 정의
typedef int (*calcFuncPtr)(int, int);


// 덧셈 함수
int plus (int first, int second)
{
    return first + second;
}
// 뺄셈 함수
int minus (int first, int second)
{
    return first - second;
}
// 곱셈 함수
int multiple (int first, int second)
{
    return first * second;
}
// 나눗셈 함수
int division (int first, int second)
{
    return first / second;
}

// 매개변수로 함수포인터를 갖는 calculator 함수
int calculator (int first, int second, calcFuncPtr func)
{
    return func (first, second);     // 함수포인터의 사용
}

int main(int argc, char** argv)
{
    calcFuncPtr calc = NULL;
    int a = 0, b = 0;
    char op = 0;
    int result = 0;

    scanf ("%d %c %d", &a, &op, &b);

    switch (op)    // 함수포인터 calc에 op에 맞는 함수들의 주소를 담음
    {
        case '+' :
            calc = plus;
            break;

        case '-':
            calc = minus;
            break;

        case '*':
            calc = multiple;
            break;

        case '/':
            calc = division;
            break;
    }

    result = calculator (a, b, calc);

    printf ("result : %d", result);

    return 0;
}
