#include <stdio.h>

long factorial(int n);

/**
 * 用迭代方法计算 n 的阶乘
 */
long
factorial(int n)
{
    int result = 1;
    while(n > 1) {
        result *= n;
        n--;
    }
    return result;
}

int main()
{
    int n = 10;
    printf("factorial %d-->%d\n", n, factorial(n));
    return 0;
}
