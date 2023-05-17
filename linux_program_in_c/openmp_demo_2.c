#include <omp.h>
#include <stdio.h>

#define N 100

int main(int argc, char const *argv[])
{
    int i, sum = 0;
    int a[N];
    int b[N];

    for (i = 0; i < N; i++)
    {
        a[i] = i;
        b[i] = 2 * i;
    }

#pragma omp parallel for
    // can not use OMP, because the Data Dependency
    for (i = 0; i < N; i++)
    {
        sum = sum + a[i] + b[i];
    }
    printf("The sum of the arrays is: %d\n", sum);

    return 0;
} // main