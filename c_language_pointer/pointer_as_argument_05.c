#include <stdio.h>

void increment(int *p)
{
    *p = (*p) + 1;
}
int main(int argc, char const *argv[])
{
    /* ... */
    int a = 10;
    printf("Before call increment method a = %d\n", a);
    increment(&a);
    printf("After call increment method a = %d\n", a);
    return 0;
} // main