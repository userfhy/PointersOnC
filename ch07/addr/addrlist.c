/**
 * 用于维护一个地址列表的抽象数据类型
 */
#include "addrlist.h"
#include <stdio.h>
#include <string.h>

/**
 * 每个地址的三个部分，分别保存于三个数组对应的元素中
 */

/*static char name[MAX_ADDRESSES][NAME_LENGTH];
static char address[MAX_ADDRESSES][ADDR_LENGTH];
static char phone[MAX_ADDRESSES][PHONE_LENGTH];
*/
static char name[MAX_ADDRESSES][NAME_LENGTH] = {"fhy", "aaa"};
static char address[MAX_ADDRESSES][ADDR_LENGTH] = {"开封", "shanghai"};
static char phone[MAX_ADDRESSES][PHONE_LENGTH] = {"138", "1008611"};

/**
 * 这个函数在数组中查找一个名字并返回查找到的位置的下标
 * 如果这个名字在数组中不存在，函数返回-1
 */
static int
find_entry(char const *name_to_find)
{
    int entry;
    for(entry = 0; entry < MAX_ADDRESSES; entry +=1) {
        if( strcmp(name_to_find, name[entry]) == 0 ) {
            return entry;
        }
    }
    return -1;
}

/**
 * 给定一个名字，查找并返回对应的地址
 * 如果名字没有找到，函数返回一个 NULL 指针
 */
char const *
lookup_address(char const *name)
{
    int entry;
    entry = find_entry(name);
    if( entry == -1 ){
        return NULL;
    }else {
        return address[entry];
    }
}

/**
 * 给定一个名字，查找并返回对应的电话号码
 * 如果名字没有找到，函数返回一个 NULL 指针
 */
char const *
lookup_phone(char const *name)
{
    int entry;
    entry = find_entry(name);
    if( entry == -1 ) {
        return NULL;
    }else {
        return phone[entry];
    }
}

int main()
{
    char *find_name[] = {"fhy", "aaa", "2"};
    int num = sizeof(find_name)/sizeof(char*);
    for(int i = 0; i < num; ++i) {
        printf("Address:%s Phone:%s\n", lookup_address(find_name[i]), lookup_phone(find_name[i]));
    }
    return 0;
}
