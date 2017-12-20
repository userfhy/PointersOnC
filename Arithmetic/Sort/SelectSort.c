/**
 * @example  选择排序
 * @author   Fhy
 * @date     2017/12/20
 * @license  MIT
 * -------------------------------------------------------------
 * 不稳定的排序方法
 * 它的工作原理是每一次从待排序的数据元素中选出最小（或最大）的一个元素，存放在序列的起始位置，直到全部待排序的数据元素排完。
 */
#include <stdio.h>

void
BubbleSort(int a[], int count)
{
    int i,j,k,temp;
    for(i = 0; i < count; i++ ) {
        k = i;
        for(j = i + 1; j < count; j++) {
            if( a[j] < a[k]) {
                k = j;
            }
        }

        if(k != i) {
            temp = a[i];
            a[i] = a[k];
            a[k] = temp;
        }
    }
}

void
printA1(int a[], int length) {
    int i;
    for(i = 0; i < length; ++i){
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main(void)
{
    int i, N;
    int b[] = {4, 21, 41, 2, 53, 1, 2132, 31, 21, 423};
    N = sizeof(b)/sizeof(int);
    printf("Before Ordering\n");
    printA1(b, N);
    BubbleSort(b, N);
    printf("After Ordering\n");
    printA1(b, N);

    return 0;
}
/**
Before Ordering
4 21 41 2 53 1 2132 31 21 423
After Ordering
1 2 4 21 21 31 41 53 423 2132
*/
