#include <stdio.h>

long fibonacci(int n);

/**
 * 用递归方法计算第 n 个斐波那契的值
 */
long
fibonacci(int n)
{
    if( n <= 2 ) {
        return 1;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
    int n = 10;
    printf("fibonacci %d-->%d\n", n, fibonacci(n));
    return 0;
}
