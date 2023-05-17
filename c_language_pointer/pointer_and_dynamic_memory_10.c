#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int a; // local variable goes on stack
    int *p;
    p = (int *)malloc(sizeof(int));
    // malloc function, how much memory to allocate on the heap in bytes
    // pass the sizeoof int type
    *p = 10;
    free(p); // one call for malloc(), one free() for it
    p = (int *)malloc(sizeof(int));
    *p = 20;
    free(p);
    p = (int *)malloc(20 * sizeof(int));

    return 0;
} // main

/*
// dma in c++
int main(int argc, char const *argv[])
{
    int a; // local variable goes on stack
    int *p;
    p = new int;
    *p = 10;
    delete p;
    p = new int[20];
    delete[] p;

    return 0;
} // main
*/