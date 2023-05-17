#include <omp.h>
#include <stdio.h>

int main()
{
    int i, n = 100;
    int a[n];
    for (i = 0; i < n; i++)
    {
        a[i] = i * 2;
    }

#pragma omp parallel for
    for (i = 0; i < n; i++)
    {
        a[i] = a[i] + 1;
    }

    for (i = 0; i < n; i++)
    {
        printf("a[%d] = %d\n", i, a[i]);
    }

    return 0;
}
