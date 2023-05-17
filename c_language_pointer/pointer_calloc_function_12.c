#include <stdio.h>
#include <stdlib.h>

/**
 * Function name: calloc(size_t nitems, size_t size)
 * Description: allocates the requested memory and returns a pointer to it
 * Parameter:
 * @nitems  the number of elements to be allocated.
 * @size    the size of the elements
 */
int main(int argc, char const *argv[])
{
    int n;
    printf("Enter size of array\n");
    scanf("%d", &n);                        // receives an array
    int *A = (int *)calloc(n, sizeof(int)); // dynamically allocated array
    for (int i = 0; i < n; i++)
    {
        A[i] = i + 1;
    } // for

    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    } // for
    free(A);
    return 0;
} // main
