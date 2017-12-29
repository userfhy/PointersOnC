/**
 * @example  快速排序
 * @author   Fhy
 * @website  https://aiti.fun
 * @date     2017/12/29
 * @license  MIT
 * -------------------------------------------------------------
 * 思路分析：从数列中挑出一个元素，称为 “基准”（pivot)
 * -------------------------------------------------------------
 * 重新排序数列，所有元素比基准值小的摆放在基准前面
 * 所有元素比基准值大的摆在基准的后面（相同的数可以到任一边）。
 * 递归地（recursive）把小于基准值元素的子数列和大于基准值元素的子数列排序
 */
#include <stdio.h>

#define SWAP(x, y, t) ((t) = (x), (x) = (y), (y) = (t))

void
QuickSort(int *a, int count, int begin, int end)
{
    int i,j, temp;
    if( begin < end ) {
        i = begin + 1; // 将a[begin]作为基准数，因此从a[begin+1]开始与基准数比较！
        j = end; // a[end]为数组最后一位

        while(i < j) {
            if( a[i] > a[begin] ) { // 如果比较的数组元素大于基准数，则交换位置。
                SWAP(a[i], a[j], temp);
                j--;
            }else {
                i++; // 将数组向后移一位，继续与基准数比较
            }
        }

        /* 跳出while循环后，i = j。
         * 此时数组被分割成两个部分  -->  a[begin+1] ~ array[i-1] < a[begin]
         *                           -->  a[i+1] ~ array[end] > array[begin]
         * 这个时候将数组a分成两个部分，再将a[i]与a[begin]进行比较，决定a[i]的位置。
         * 最后将a[i]与a[begin]交换，进行两个分割部分的排序！以此类推，直到最后i = j不满足条件就退出！
         */
        if( a[i] >= a[begin] ) {   // 这里必须要取等“>=”，否则数组元素由相同的值时，会出现错误
            i--;
        }
        SWAP(a[begin], a[i], temp);
        QuickSort(a, count, begin, i);
        QuickSort(a, count, j, end);
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
    int b[] = {4, 21, 413, 20, 2, 53, 1, 2132, 31, 21, 423};
    N = sizeof(b)/sizeof(int);
    printf("Before Ordering\n");
    printA1(b, N);
    QuickSort(b, N, 0, N - 1);
    printf("After Ordering\n");
    printA1(b, N);

    return 0;
}

/**
Before Ordering
4 21 413 20 2 53 1 2132 31 21 423
After Ordering
1 2 4 20 21 21 31 53 413 423 2132
*/
