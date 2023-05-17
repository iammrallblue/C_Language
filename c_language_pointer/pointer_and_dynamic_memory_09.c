#include <stdio.h>

int total; // global variable
int Square(int x)
{
    return x * x;
} // Square

int SquareOfSum(int x, int y)
{
    int z = Square(x + y);
    return z;
} // SquareOfSum

int main(int argc, char const *argv[])
{
    int a = 4, b = 8;
    total = SquareOfSum(a, b);
    printf("output = %d\n", total);
    return 0;
} // main
