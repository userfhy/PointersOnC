/**
 * @example  顺序查找
 * @author   Fhy
 * @website  https://aiti.fun
 * @date     2017/12/20
 * @license  MIT
 * -------------------------------------------------------------
 * 基本思路： 用顺序结构存储数据（数组、链表），从前到后依次查询目标值，
 * 如果发现则返回查找到的值，否则返回0.
 * -------------------------------------------------------------
 * 找成功时的平均查找长度为：（假设每个数据元素的概率相等） ASL = 1/n(1+2+3+…+n) = (n+1)/2 ;
 * 当查找不成功时，需要n+1次比较，时间复杂度为O(n);
 * 所以，顺序查找的时间复杂度为O(n)。
 */
#include <stdio.h>

int FindBySeq(int *ListSeq, int ListLength, int KeyData);

int main()
{
    int TestData[] = { 34, 35, 26, 89, 56 };
    int N = sizeof(TestData)/sizeof(TestData[0]);
    int retData = FindBySeq(TestData, N, 89);
    printf("retData index--> %d\n", retData);
    return 0;
}

int FindBySeq(int *ListSeq, int ListLength, int KeyData)
{
    int tmp = 0;
    int length = ListLength;
    int i;
    for (i = 0; i < ListLength; i++) {
        if (ListSeq[i] == KeyData) {
            return i;
        }
    }
    return 0;
}
