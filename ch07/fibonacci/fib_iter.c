#include <stdio.h>

long fibonacci(int n);

/**
 * 用迭代方法计算第 n 个斐波那契的值
 */
long
fibonacci(int n)
{
    long result, previous_result, next_older_result;
    result = previous_result = 1;
    while(n > 2) {
        n--;
        next_older_result = previous_result;
        previous_result = result;
        result = previous_result + next_older_result;
    }
    return result;
}

int main()
{
    int n = 20;
    printf("fibonacci %d-->%d\n", n, fibonacci(n));
    return 0;
}
