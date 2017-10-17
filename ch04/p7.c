#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define CHAR_MAX 1000
#define NUL '\0'

int isWhite(char ch)
{
  return ch == ' '|| ch == '\r' || ch == '\n' || ch == '\f' || ch == '\t' || ch == '\v';
}

void debank(char string[])
{
  char *src;
  char *des;
  int ch;

  src = string;
  des = string++;

  while ( ( ch = *src++) != NUL ) {
    if ( isWhite(ch) ) {
        if (src == string || !isWhite( des[-1] )) {
          *des++ = ' ';
        }
    }else {
      *des++ = ch;
    }
  }
  *des = NUL;
}

int main(int argc, char const *argv[]) {
  char str[60] = "dfsdfa abc e";
  debank( str );
  printf("%s\n", str );
  return 0;
}
