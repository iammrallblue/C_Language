#include <stdio.h>

int main(int argc, char const *argv[])
{
    int x, y, z;

    printf("\nEnter two numbers: ");
    scanf("%d %d", &x, &y);

    z = x + y;

    printf("%d + %d = %d", x, y, z);

    return 0;
}
