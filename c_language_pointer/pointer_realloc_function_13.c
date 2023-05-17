#include <stdio.h>
#include <stdlib.h>

/**
 * Function name: realloc()
 * Description: allocates the requested memory and returns a pointer to it
 * Parameter:
 * @size    the size of the memmory block, in bytes.
 */
int main(int argc, char const *argv[])
{
    int n;
    printf("Enter size of array\n");
    scanf("%d", &n);                         // receives an array
    int *A = (int *)malloc(n * sizeof(int)); // dynamically allocated array
    for (int i = 0; i < n; i++)
    {
        A[i] = i + 1;
    } // for
    // free(A); // assign 0s to array
    // int *A = (int*)realloc(A, 0); == free(A);
    // A[3] = 2333; // assign value 2333 to the index 3 in the array
    // A = NULL; // after free, adjust point to NULL

    int *B = (int *)realloc(A, 2 * n * sizeof(int));
    printf("previous block address = %d, new address = %d\n", A, B);
    for (int i = 0; i < 2 * n; i++)
    {
        printf("%d ", B[i]);
    } // for
    // free(A);
    return 0;
} // main
