#include <stdio.h>
#include <stdlib.h>

size_t
my_strlen(char *string)
{
    int length = 0;
    // 依次访问字符串的内容，计数字符串
    // 知道遇见 NUL 终止符
    while(*string++ != '\0') {
        length += 1;
    }
    return length;
}

int main(void)
{
    char s[] = "fhy";
    printf("%s-->%d\n", s, my_strlen(s));
    return 0;
}
