#include <stdio.h>

int main()
{
    // arithmetic operators
    // + (addition)
    // - (subtraction)
    // * (multiplication)
    // / (division)
    // % (modulus)
    // ++ increment
    // -- decrement

    int x = 5;
    int y = 2;

    float z = x / y;

    printf("%f\n", z);

    float zz = x % y;

    printf("%f\n", zz);

    printf("%f", ++zz);
    return 0;
}