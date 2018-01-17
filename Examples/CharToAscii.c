#include <stdio.h>
int main()
{
    char c;
    printf("输入一个字符: ");

    // 读取用户输入
    scanf("%c", &c);

    // %d 显示整数
    // %c 显示对应字符
    printf("%c 的 ASCII 为 %d", c, c);
    return 0;
}
