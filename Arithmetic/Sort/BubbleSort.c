/**
 * @example  冒泡排序
 * @author   Fhy
 * @website  https://aiti.fun
 * @date     2017/12/20
 * @license  MIT
 * -------------------------------------------------------------
 * 思路分析：就是像冒泡一样，每次从数组当中 冒一个最大的数出来。 
 * -------------------------------------------------------------
 * 你可以这样理解：（从小到大排序）存在10个不同大小的气泡，
 * 由底至上的把较少的气泡逐步地向上升，这样经过遍历一次后最小的气泡就会被上升到顶（下标为0）
 * 然后再从底至上地这样升，循环直至十个气泡大小有序。
 * 在冒泡排序中，最重要的思想是两两比较，将两者较少的升上去
 *
 */
#include <stdio.h>

void
BubbleSort(int *a, int count)
{
    int i,j,t;
    for(i = 1; i < count; i++) {
        for(j = 0; j < count - i; j++) {
            if( a[j] > a[j+1] ) {
                t = a[j];
                a[j] = a[j+1];
                a[j+1] = t;
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
