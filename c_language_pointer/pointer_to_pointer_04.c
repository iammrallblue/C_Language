#include <stdio.h>

int main(int argc, char const *argv[])
{
    /* pointer to pointer */
    int x = 5;
    int *p = &x; // pointer p has the a's address
    *p = 6;      // change a's value, same as a = 6;
    // declare a pointer points to a pointer
    int **q = &p;  // pointer q has the pointer a's address
    int ***r = &q; // pointer r has the pointer q's address

    printf("p contains x's address = %d\n", p);   // x's address 225
    printf("*p has x's value = %d\n", *p);        // *p = 6, so x = 6
    printf("*q contains x's address = %d\n", *q); // x's address 225
    printf("*(*q) has x's value = %d\n", *(*q));  // has x's value 6
    printf("**q = %d\n", **q);                    // *(*q) **q are the same.
    // printf("**q = %d\n", );
    printf("*(*r) contains x's address = %d\n", *(*r)); // x's address 225
    printf("*(*(*r)) has x's value = %d\n", *(*(*r)));  // has x's value 6

    **q = *p + 100;        // 6 + 100
    printf("x = %d\n", x); // x = 106

    ***r = 200;
    printf("x = %d\n", x); // x = 200

    **q = *p + 2;
    printf("x = %d\n", x);
    return 0;
} // main
