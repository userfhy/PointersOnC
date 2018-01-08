#include <stdio.h>

int main()
{
    int integerType;
    float floatType;
    double doubleType;
    char charType;

    // sizeof 操作符用于计算变量的字节大小
    printf("Size of int:\t %ld bytes\n",sizeof(integerType));
    printf("Size of float:\t %ld bytes\n",sizeof(floatType));
    printf("Size of double:\t %ld bytes\n",sizeof(doubleType));
    printf("Size of char:\t %ld byte\n",sizeof(charType));

    // long
    int a;
    long b;
    long long c;

    double e;
    long double f;

    printf("Size of int:\t %ld bytes \n", sizeof(a));
    printf("Size of long:\t %ld bytes\n", sizeof(b));
    printf("Size of long long: %ld bytes\n", sizeof(c));

    printf("Size of double:\t %ld bytes\n", sizeof(e));
    printf("Size of long double: %ld bytes\n", sizeof(f));

    return 0;
}
