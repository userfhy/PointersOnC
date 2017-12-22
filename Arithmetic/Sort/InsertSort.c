/**
 * @example  选择排序
 * @author   Fhy
 * @website  https://aiti.fun
 * @date     2017/12/22
 * @license  MIT
 * -------------------------------------------------------------
 * 思路分析：每步将一个待排序的纪录，按其关键码值的大小插入前面已经排序的文件中适当位置上，直到全部插入完为止。
 * -------------------------------------------------------------
 *
 * 算法适用于少量数据的排序，时间复杂度为O(n^2)。是稳定的排序方法。
 * 插入算法把要排序的数组分成两部分：第一部分包含了这个数组的所有元素，
 * 但将最后一个元素除外（让数组多一个空间才有插入的位置），而第二部分就只包含这一个元素（即待插入元素）。
 * 在第一部分排序完成后，再将这个最后元素插入到已排好序的第一部分中。
 */
#include <stdio.h>

void
InsertSort(int *a, int count)
{
    int i,j,k,temp;
    for(i = 1; i < count; i++) {
        temp = a[i];
        j = i - 1;
        while(a[j] > temp) {
            a[j+1] = a[j];
            a[j] = temp;
            j--;
            if( j < 0 ) {
                break;
            }
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
    InsertSort(b, N);
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
