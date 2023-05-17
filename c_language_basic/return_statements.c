#include <stdio.h>

double square(double x)
{
    double result = x * x;

    return result;
}

int main(int argc, char const *argv[])
{
    double x = square(3.14);
    printf("%lf", x);

    return 0;
}
