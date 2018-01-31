/**
 * @example  索引查找
 * @author   Fhy
 * @website  https://aiti.fun
 * @date     2018/01/31
 * @license  MIT
 * -------------------------------------------------------------
 * 基本思路：索引查找又称为分块查找，即把线性表分成若干块，在每一块中记录的关键字不一定有序，但是块与块之间必须有序。
 * 假设这种排序是按关键字值递增排序的，抽取各块中的最大关键字及该块的起始位置构成索引表，
 * 按块的顺序存放在一个数组中，显然这个数组是有序的，一般按升序排列
 * -------------------------------------------------------------
 * key: 索引表中的关键字。
 * address: 索引表对应块的首地址。
 * length: 索引表对应块的长度。
 * 可以先对索引表进行折半查找，找出对应的块，然后再在对应的快中利用顺序查找找出需要查找的关键字。
 */

#include <stdio.h>

struct idtable {
    int key;
    int address;
    int length;
};

int indexSearch(int *a, int a_length, struct idtable idtables[], int idtables_length, int keyword);

int indexSearch(int *a, int a_length, struct idtable idtables[], int idtables_length, int keyword) {
    // 先用二分查找法找出对应的块号
    int low1 = 0, high1 = idtables_length - 1, mid = 0;
    while (low1 <= high1) {
        mid = (low1 + high1) / 2;
        if (keyword <= idtables[mid].key) {
            high1 = mid - 1;
        } else {
            low1 = mid + 1;  // 查找完毕，low1存放块号
        }
    }

    if (low1 < idtables_length) {
        int index = -1;
        // low2为块在表中的起始地址
        int low2 = idtables[low1].address, high2 = 0;
        if (low1 == idtables_length - 1) {
            high2 = a_length - 1;
        } else {
            high2 = idtables[low1 + 1].address - 1;
        }

        // 用顺序查找法在对应的块中找出符合条件的值
        int i;
        for (i = low2; i <= high2; i++) {
            if (a[i] == keyword) {
                index = i;
                break;
            }
        }

        return index;
    } else {
        return -1;
    }
}

int main(int argc, const char * argv[]) {

    // 主表
    int a[] = {22, 12, 13, 8, 9, 20, 33, 42, 44, 38, 24, 46, 60, 58, 74, 47, 86, 53};
    // 索引表
    struct idtable idtables[3] = {
        {22, 0, 6},
        {46, 6, 6},
        {86, 12, 6}
    };

    int a_length, idtables_length;
    a_length = sizeof(a)/sizeof(a[0]);
    idtables_length = sizeof(idtables)/sizeof(idtables[0]);
    // printf("a_length: %d  idtables_length: %d\n", a_length, idtables_length);

    int result = indexSearch(a, a_length, idtables, idtables_length, 74);

    printf("index:%d\n", result);

    return 0;
}