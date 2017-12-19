#include <stdio.h>

void binary_to_ascii(unsigned int value);

/**
 * 接受一个整型数（无符号），把它转换为字符并打印它。前导零被删除。
 */
void
binary_to_ascii(unsigned int value)
{
    unsigned int quotient;
    quotient = value / 10;
    if( quotient != 0 ) {
        binary_to_ascii(quotient);
    }
    putchar(value % 10 + '0');
}

int main()
{
    binary_to_ascii(560010);
    return 0;
}
