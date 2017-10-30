#include<stdio.h>

unsigned int reverse( unsigned int value )
{
  unsigned int answer = 0;
  unsigned int i;

  for ( i = 1; i != 0 ; i <<= 1) {
    answer <<= 1;
    if( value & 1 ){
        answer |= 1;
    }
    value >>= 1;
  }

  return answer;
}
int main(int argc, char const *argv[]) {
  printf("%d\n", reverse(25) );
  return 0;
}
