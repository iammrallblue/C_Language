#include <stdio.h>

int main(int argc, char const *argv[])
{
    /* Array in the memory */
    int A[] = {2, 4, 5, 8, 1};
    int *p = A; // same as int *p = A[0]
    // A++; // A++ is invalid
    // p++; // valid

    // access the array directly
    printf("The address of array A = %d\n", A); // A == &A[0]
    printf("&A[0] is same as the address of the array A. %d\n", &A[0]);
    // the addresss the array A is just the address of the first element in the array A
    printf("The first element A[0] of the Array A = %d\n", A[0]); // A[0] == *A

    printf("p is: %d\n", p);   // same A[0] 200
    printf("*p is: %d\n", *p); // print out the first element 2

    printf("p+1 is: %d\n", p + 1);       // same A[0] + 1
    printf("*(p+1) is: %d\n", *(p + 1)); // print out the second element 4

    // iterating by for loop,
    for (int i = 0; i < 5; i++)
    {
        // all addresses of the array
        printf("Address = %d\n", &A[i]);   // 4 bytes for each element
        printf("Address = %d\n", A + i);   // each i has 4 bytes
        printf("Address = %d\n", p + (i)); // print out each address

        // print out the values of each array element
        printf("value = %d\n", A[i]);     // each value in the Array
        printf("value = %d\n", *(A + i)); // each value in the Array
    }                                     // for
    return 0;
} // main
