#include <stdio.h>
/**
 * 计算 M N 的最大公约数并返回
 */
int
gcd(int M, int N)
{
    if( M < 0 || N < 0 ) {
        return 0;
    }
    int R = M % N;
    if( R == 0 ) {
        return N;
    }
    if( R > 0 ) {
        gcd(N, R);
    }
}

int main()
{
    int res = gcd(12, 0);
    printf("Highest common divisor: %d\n", res);
    return 0;
}
