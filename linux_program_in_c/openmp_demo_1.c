#include <stdio.h>
#include <omp.h>

int main(int argc, char const *argv[])
{
    int n = 100;
    int i;
    double x, pi;

#pragma omp parallel for reduction(+ \
                                   : pi)

    for (i = 0; i < n; i++)
    {
        x = (double)i / n;
        pi += 4.0 / (1.0 + x * x);
    }
    pi /= n;

    return 0;
} // main
