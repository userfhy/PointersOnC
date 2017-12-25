#include <stdio.h>

static double income_limits[] = { 0, 23350, 56550, 117950, 256500 };

static float base_tax[] = { 0, 3502.5, 12798.5, 31832.5, 81710.5 };

static float percentage[] = { 0.15, 0.28, 0.31, 0.36, 0.396 };

float single_tax( float income )
{
    int category = 1;
    while( income > income_limits[category] ) {
        category++;
    }
    category--;

    return base_tax[category] + ( income - income_limits[category] ) * percentage[ category ];
}

int main(int argc, char const *argv[])
{
    printf("%.2f\n", single_tax(100000) );
    return 0;
}
