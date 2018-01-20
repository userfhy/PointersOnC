#include <stdio.h>

int main()
{
    int n, reversedInteger = 0, remainder, originalInteger;

    printf("输入一个整数: ");
    scanf("%d", &n);

    originalInteger = n;

    // 翻转
    while( n != 0 ) {
        remainder = n % 10;
        reversedInteger = reversedInteger * 10 + remainder;
        n /= 10;
    }

    // 判断
    if ( originalInteger == reversedInteger ) {
        printf("%d 是回文数。", originalInteger);
    } else {
        printf("%d 不是回文数。", originalInteger);
    }

    return 0;
}
