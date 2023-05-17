#include <stdio.h>

int main(int argc, char const *argv[])
{
    int a = 10;
    int *p = &a;
    // Pointer Arithmetic
    printf("p = %p\n", p); // p = 2002
    // show size of int type
    printf("size of int is: %ld bytes\n", sizeof(int));
    printf("p+1 = %p\n", p + 1); // p+1 = 2006

    return 0;
} // main
