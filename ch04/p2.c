#include <stdio.h>

#define NPRIMES 1000
#define FALSE 0
#define TRUE 1

int main(void) {
    int n, i, j, flag;
    // 保存比n小的素数
    int primes[NPRIMES];
    // 当前素数的数目加1
    int level;

    printf("Enter value of N >");
    scanf("%d", &n);
    level = 0;

    for(i = 2; i <= n; i++) {
        for(j = 0, flag = TRUE; j < level && flag; j++) {
            flag = (i % primes[j]);
        }

        if(flag) {
            printf("%12d\n", i);
            if( level < NPRIMES ) {
                primes[level++] = i;
            }
        }
    }
}
