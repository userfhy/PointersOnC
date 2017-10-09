#include <stdio.h>
#include <stdlib.h>

/** 
 * programing 2
 *
 * compile & run
 * # gcc p2.c -o p2 && ./p2 < test_c.log 
 * Output: 4 matched!
 **/
int main()
{
    int ch;
    int braces = 0;
    int num = 0;

    while( (ch = getchar()) != EOF ) {
        if( ch == '{' ) {
            braces += 1;
        }

        if( ch == '}' ) {
            if( braces == 0 ) {
                printf("Extra closing brace!\n");
            } else {
                braces -= 1;
                num++;
            }
        }
    }
    
    if( braces > 0 ) {
        printf("%d unmatched opening brace(s)!\n", braces);
    }else {
        printf("%d matched!\n", num);
    }

    return EXIT_SUCCESS;
}
