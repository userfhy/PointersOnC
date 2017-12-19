#include <stdio.h>

long factorial(int n);

/**
 * 用递归方法计算 n 的阶乘
 */
long
factorial(int n)
{
    if( n <= 0 ) {
        return 1;
    }else {
        return n * factorial(n - 1);
    }
}

int main()
{
    int n = 10;
    printf("factorial %d-->%d\n", n, factorial(n));
    return 0;
}
