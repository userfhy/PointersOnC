#include <stdio.h>

int main()
{
    int a = 20;
    if( 1 <= a <= 11 ) {
        printf("In range\n");
    }else {
        printf("Out of range\n");
    }

    // 正确写法
    if( 1 <= a && a <= 11 ) {
        printf("In range\n");
    }else {
        printf("Out of range\n");
    }
}
