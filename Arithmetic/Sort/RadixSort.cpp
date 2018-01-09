#include <iostream>
#include <vector>

using namespace std;

// 求出数组中最大数的位数的函数
int MaxBit(vector<int> input) {
    // 数组最大值
    int max_data = input[0];
    for (int i = 1; i < input.size(); i++){
        if (input[i] > max_data){
            max_data = input[i];
        }
    }

    // 数组最大值的位数
    int bits_num = 0;
    while (max_data){
        bits_num++;
        max_data /= 10;
    }

    return bits_num;
}

// 取数xxx上的第d位数字
int digit(int num, int d) {
    int pow = 1;
    while (--d > 0){
        pow *= 10;
    }
    return num / pow % 10;
}

// 基数排序
vector<int> RadixSort(vector<int> input, int n) {
    // 临时数组，用来存放排序过程中的数据
    vector<int> bucket(n);
    // 位记数器，从第0个元素到第9个元素依次用来记录当前比较位是0的有多少个...是9的有多少个数
    vector<int> count(10);
    // 从低位往高位循环
    for (int d = 1; d <= MaxBit(input); d++){
        // 计数器清0
        for (int i = 0; i < 10; i++){
            count[i] = 0;
        }

        // 统计各个桶中的个数
        for (int i = 0; i < n; i++){
            count[digit(input[i],d)]++;
        }

        /*
        * 比如某次经过上面统计后结果为：[0, 2, 3, 3, 0, 0, 0, 0, 0, 0]则经过下面计算后 结果为： [0, 2,
        * 5, 8, 8, 8, 8, 8, 8, 8]但实质上只有如下[0, 2, 5, 8, 0, 0, 0, 0, 0, 0]中
        * 非零数才用到，因为其他位不存在，它们分别表示如下：2表示比较位为1的元素可以存放在索引为1、0的
        * 位置，5表示比较位为2的元素可以存放在4、3、2三个(5-2=3)位置，8表示比较位为3的元素可以存放在
        * 7、6、5三个(8-5=3)位置
        */
        for (int i = 1; i < 10; i++){
            count[i] += count[i - 1];
        }

        /*
        * 注，这里只能从数组后往前循环，因为排序时还需保持以前的已排序好的顺序，不应该打
        * 乱原来已排好的序，如果从前往后处理，则会把原来在前面会摆到后面去，因为在处理某个
        * 元素的位置时，位记数器是从大到到小（count[digit(arr[i], d)]--）的方式来处
        * 理的，即先存放索引大的元素，再存放索引小的元素，所以需从最后一个元素开始处理。
        * 如有这样的一个序列[212,213,312]，如果按照从第一个元素开始循环的话，经过第一轮
        * 后（个位）排序后，得到这样一个序列[312,212,213]，第一次好像没什么问题，但问题会
        * 从第二轮开始出现，第二轮排序后，会得到[213,212,312]，这样个位为3的元素本应该
        * 放在最后，但经过第二轮后却排在了前面了，所以出现了问题
        */
        for (int i = n - 1; i >= 0; i--){
            int k = digit(input[i], d);
            bucket[count[k] - 1] = input[i];
            count[k]--;
        }

        // 临时数组复制到 input 中
        for (int i = 0; i < n; i++){
            input[i] = bucket[i];
        }
    }

    return input;
}

int main(void)
{
    int arr[] = { 50, 123, 543, 187, 49, 30, 0, 2, 11, 100 };
    vector<int> test(arr, arr + sizeof(arr) / sizeof(arr[0]));
    cout << "排序前:";
    for (int i = 0; i < test.size(); i++){
        cout << test[i] << " ";
    }
    cout << endl;

    vector<int> result = test;
    result = RadixSort(result, result.size());
    cout << "排序后:";
    for (int i = 0; i < result.size(); i++){
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}
