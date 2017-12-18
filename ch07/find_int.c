#include <stdio.h>

int *find_int(int key, int array[], int array_len);

/**
 * Function: find_int
 * Description: 在数组中寻找特定整型值的存储位置，并返回一个指向该位置的指针。
 * Input: key 要查找的值 array 对应数组 array_len 数组元素个数
 */
int
*find_int(int key, int array[], int array_len)
{
    int i;
    // 对于数组中的每个位置
    for(i = 0; i < array_len; i+=1) {
        if( array[i] == key ){
            return &array[i];
        }
    }
    return NULL;
}

int main()
{
    int a[] = {1, 2, 3, 4, 5, 6, 82};
    int *p = find_int(6, a, sizeof(a));
    // p 返回位置对应指针既地址 *p 所在地址中的数据
    printf("pointer: %p data: %d\n", p, *p);
}

