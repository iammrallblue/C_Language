#include <stdio.h>
#include <stdlib.h>

/* Pointer as function returns */
int *Add(int *a, int *b)
{
    // a and b are pointers to integers
    int c = (*a) + (*b);
    printf("&a = %d\n", &a);        //&a is the address of pointer variable
    printf("a in Add() = %d\n", a); // a is the variable in main()
    printf("*a = %d\n", *a);        // *a is 2, 2 is passed by
    return &c;
}
int main(int argc, char const *argv[])
{
    int a = 2, b = 4;
    int *z = Add(&a, &b);
    printf("Sum = %d\n", *z);
    printf("a in main() = %d\n", &a);
    return 0;
} // main

// /* Pass variable as parameters of function */
// int Add(int a, int b) // Add() is a called function, called by a calling function
// {
//     printf("The address of a = %d\n", &a);
//     int c = a + b;
//     return c;
// } // Add
// int main(int argc, char const *argv[]) // main() is a calling function
// {
//     /* x,y, z are local variables */
//     int a = 2, b = 4;
//     printf("The address of a = %d\n", a);
//     int z = Add(a, b);
//     printf("Sum = %d\n ", z);
//     return 0;
// } // main
