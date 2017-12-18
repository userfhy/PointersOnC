#include <stdio.h>

void swap(int *a, int *b);

/**
 * 指针交换两个数的值
 */
void
swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int i,j;
    i = 666;
    j = 255;
    printf("Before: i: %d j: %d\n", i, j);
    swap(&i, &j);
    printf("After: i: %d j: %d\n", i, j);
    return 0;
}
