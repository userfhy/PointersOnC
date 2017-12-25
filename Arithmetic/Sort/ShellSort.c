/**
 * @example  希尔排序
 * @author   Fhy
 * @website  https://aiti.fun
 * @date     2017/12/22
 * @license  MIT
 * -------------------------------------------------------------
 * 思路分析：先将整个待排序的记录序列分割成为若干子序列分别进行直接插入排序，待整个序列中的记录“基本有序”时，再对全体记录进行依次直接插入排序。
 * -------------------------------------------------------------
 * 先将要排序的一组记录按某个增量d（n/2,n为要排序数的个数）分成若干组子序列，每组中记录的下标相差d.
 * 对每组中全部元素进行直接插入排序，然后再用一个较小的增量（d/2）对它进行分组，在每组中再进行直接插入排序。
 * 继续不断缩小增量直至为1，最后使用直接插入排序完成排序。
 */
#include <stdio.h>

void
ShellSort(int *a, int count)
{
    int i,j,dk,temp;
    for(dk = count / 2; dk > 0; dk /= 2) { // 用来控制步长，最后递减到1
        // i从第step开始排列，应为插入排序的第一个元素
        // 可以先不动，从第二个开始排序
        for(i = dk; i < count; i++) {
            temp = a[i];
            for(j = i - dk; j >= 0 && temp < a[j]; j -= dk) {
                a[j+dk] = a[j];
            }
            a[j+dk] = temp; // 将第一个位置填上
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
    ShellSort(b, N);
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
