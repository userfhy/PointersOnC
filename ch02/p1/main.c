#include <stdio.h>

int main()
{
    printf("increment函数的参数为10时的结果：%d\n", increment( 10 ) );
    printf("increment函数的参数为0时的结果：%d\n", increment( 0 ) );
    printf("increment函数的参数为-10时的结果：%d\n", increment( -10 ) );
    printf("negate函数的参数为10时的结果：%d\n", negate( 10 ) );
    printf("negate函数的参数为0时的结果:%d\n", negate( 0 ) );
    printf("negate函数的参数为-10时的结果：%d\n", negate( -10 ));
    return 0;
}
