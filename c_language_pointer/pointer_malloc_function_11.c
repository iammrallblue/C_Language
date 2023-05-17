#include <stdio.h>
#include <stdlib.h>

/**
 * Function name: malloc(size_t size)
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
    A[3] = 2333; // assign value 2333 to the index 3 in the array
    // A = NULL; // after free, adjust point to NULL
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    } // for
    // free(A);
    return 0;
} // main
