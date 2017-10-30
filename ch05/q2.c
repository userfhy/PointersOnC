#include<stdio.h>

int func(void)
{
    static int counter = 1;
    return ++counter;
}

int main() {
    int answer;
    answer = func() - func() * func();
    printf("%d\n", answer);
    /**
     * 静态变量的内存是整个程序开始就分配了内存,
     * 整个程序结束后内存才消失
     * output 2 - 3 * 4 = -10
     */
    return 0;
}
