/**
 * @example  插值查找
 * @author   Fhy
 * @website  https://aiti.fun
 * @date     2018/01/15
 * @license  MIT
 * -------------------------------------------------------------
 * 基本思想：基于二分查找算法，将查找点的选择改进为自适应选择，可以提高查找效率。
 * 当然，差值查找也属于有序查找。
 *
 * 注：对于表长较大，而关键字分布又比较均匀的查找表来说，插值查找算法的平均性能比折半查找要好的多。
 * 反之，数组中如果分布非常不均匀，那么插值查找未必是很合适的选择。
 * -------------------------------------------------------------
 * 复杂度分析：查找成功或者失败的时间复杂度均为O(log2(log2n))
 * mid=low+(key-a[low])/(a[high]-a[low])*(high-low)
 *
 * 说明：元素必须是有序的，如果是无序的则要先进行排序操作
 */
#include <stdio.h>
#include <stdlib.h>

int insertSearch(int *sortedSeq, int seqLength, int keyData);

int insertSearch(int *sortedSeq, int seqLength, int keyData)
{
    int low = 0, mid, high =  seqLength - 1;

    while(low <= high) {
        //mid = (low + high) / 2; // 二分查找

        // 插值查找
        mid = low + (keyData - sortedSeq[low]) / ((sortedSeq[high] - sortedSeq[low]) * (high - low));
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
    int TestData[] = {1, 2, 3, 44, 5, 89, 4, 5454};
    int intSize = sizeof(TestData[0]);
    int N = sizeof(TestData) / intSize;

    printf("排序前:\n");
    printArr(TestData, N);

    qsort(TestData, N, intSize, compare); // 首先排序

    printf("排序后:\n");
    printArr(TestData, N);

    int retData = insertSearch(TestData, N, 89);
    printf("retData index--> %d\n", retData);
    return 0;
}

