/**
 * @example  堆排序
 * @author   Fhy
 * @website  https://aiti.fun
 * @date     2018/01/09
 * @license  MIT
 * -------------------------------------------------------------
 *  排，实际上是一种选择排序，只不过采用了堆这种数据结构，利用这种数据结构，使得在每次查找最大元素时，
 *  直接选取堆顶元素，从而时间大大缩短，相对简单选择排序算法来说，比较高效。
 *  堆排序算法可描述如下:
 *  1.将待排元素依次存入数组，该数组即为一颗完全二叉树；
 *  2.从最后一个非叶节点开始递减，逐次将每个相应的二叉树调整成最大堆，最后，整个二叉树即为最大堆；
 *  3.交换堆顶元素与堆尾元素，调整新的堆为最大堆，数组分为两部分：堆与已排序列，直至最后一个堆元素。
 *  从上面可以看出，堆排序大致可以分为三个步骤：
 *  1.存入数据（完全二叉树）
 *  2.将前n个元素调整为最大堆
 *  3.交换堆顶和堆尾元素，n=n-1，转2
 *  注：本文元素从数组下标1开始储存，所以parent访问二叉树左右儿子分别为2*parent 和 2*parent+1
 **/

#include <stdio.h>

#define SWAP(x, y, t) ((t) = (x), (x) = (y), (y) = (t))
#define NA -1

void HeapAdjust(int H[],int start,int end); //堆调整，将start和end之间的元素调整为最大堆
void HeapSort(int H[],int L,int R); //堆排序

void HeapAdjust(int H[],int start,int end)
{
    int temp = H[start];
    int parent = start, child;
    while(2 * parent <= end) {
        child = 2 * parent;
        if( child != end && H[child] < H[child+1] ) {
            ++child;
        }
        if( temp>H[child] ) {
            break;
        } else {
            H[parent] = H[child];
        }
        parent = child;
    }
    H[parent] = temp;
}

void HeapSort(int H[],int L,int R)
{
    int i,t;
    for(i = (R-L+1)/2; i >= L; --i) { //调整整个二叉树为最大堆
        HeapAdjust(H,i,R);
    }

    for(i = R;i >= L; --i) {
        SWAP(H[L], H[i], t);
        HeapAdjust(H, L, i-1);
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
    int b[] = {NA, 4, 21, 41, 2, 53, 1, 2132, 31, 21, 423};
    N = sizeof(b)/sizeof(int);
    printf("Before Ordering\n");
    printA1(b, N);
    HeapSort(b, 1, N - 1); // 从1开始存入数据
    printf("After Ordering\n");
    printA1(b, N);

    return 0;
}
/**
Before Ordering
-1 4 21 41 2 53 1 2132 31 21 423
After Ordering
-1 1 2 4 21 21 31 41 53 423 2132
*/
