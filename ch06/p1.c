#include <stdio.h>
#include <string.h>

#define NUL '\0'

char const *find_char(char const *source, char const *chars)
{
    char const *temp_source = source;

    while(*chars != NUL) {
        while(*temp_source != NUL) {
            if(*temp_source == *chars){
                return temp_source;
            }
            temp_source++;
        }
        chars++;
        temp_source = source;
    }
    return NULL;
}

int main(int argc, char const *argv[]) {
    char *source = "ABCDEF";
    char *chars = "erwtEFB";
    char const * ch = NULL;
    // 内置 strpbrk 方法
    char *test = strpbrk(source, chars);
    if(test){
        printf("The result is: %s\n", test);
    }else{
        printf("Sorry!\n");
    }

    if( (ch = find_char(source, chars)) != NULL ) {
        printf("%c\n", *ch);
    }else{
        printf("NULL \n");
    }
    return 0;
}
