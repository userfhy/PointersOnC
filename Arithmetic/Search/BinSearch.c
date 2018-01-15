/**
 * @example  二分查找
 * @author   Fhy
 * @website  https://aiti.fun
 * @date     2018/01/12
 * @license  MIT
 * -------------------------------------------------------------
 * 基本思路：将排序好的数据存放到数组里（不能是链表）
 * 这只前中后标签，与中间元素比，若小于就将后变为原来的中
 * 继续计算中，比较，循环，直至等于中，或循环结束。
 * -------------------------------------------------------------
 * 复杂度分析：最坏情况下，关键词比较次数为log2(n+1)，且期望时间复杂度为O(log2n)
 *
 * 说明：元素必须是有序的，如果是无序的则要先进行排序操作。
 */
#include <stdio.h>
#include <stdlib.h>

int binSearch(int *sortedSeq, int seqLength, int keyData);

int binSearch(int *sortedSeq, int seqLength, int keyData)
{
    int low = 0, mid, high =  seqLength - 1;

    while(low <= high) {
        mid = (low + high) / 2;
        if( keyData < sortedSeq[mid] ) {
            high = mid - 1;
        } else if (keyData > sortedSeq[mid]) {
            low = mid + 1;
        } else {
            return mid;
        }
    }
    return -1;
}

int compare(const void *a , const void *b ) {

    return (*(int *)a - *(int *)b);  //升序排序

    //return *(int *)b - *(int *)a; //降序排序

/**
 * 参数列表是两个空指针，现在他要去指向你的数组元素。所以转型为你当前的类型，然后取值。
 * 升序排列时，若第一个参数指针指向的“值”大于第二个参数指针指向的“值”，则返回正；
 * 若第一个参数指针指向的“值”等于第二个参数指针指向的“值”，则返回零；
 * 若第一个参数指针指向的“值”小于第二个参数指针指向的“值”，则返回负。
 * 降序排列时，则刚好相反。
**/

}

void printArr(int *a, int length) {
    int i;
    for(i = 0; i < length; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main()
{
    int TestData[] = { 34, 35, 26, 89, 56 };
    int intSize = sizeof(TestData[0]);
    int N = sizeof(TestData) / intSize;

    printf("排序前:\n");
    printArr(TestData, N);

    qsort(TestData, N, intSize, compare); // 首先排序

    printf("排序后:\n");
    printArr(TestData, N);

    int retData = binSearch(TestData, N, 89);
    printf("retData index--> %d\n", retData);
    return 0;
}

