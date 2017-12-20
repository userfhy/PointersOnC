/**
 * 计算 Hermite polynomial 的值
 */

int
hermite(int n, int x)
{
    // 非递归情况
    if( n <= 0 ) {
        return 1;
    }
    if( n == 1 ) {
        return 2 * x;
    }

    // 递归情况
    return 2 * x * hermite(n - 1, x) - 2 * (n - 1) * hermite(n - 2, x);
}
