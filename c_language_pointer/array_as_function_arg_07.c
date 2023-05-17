#include <stdio.h>

/**
 * Function doubleElement()
 *
 */
void doubleElement(int *A, int size)
{
    int i, doubleSum = 0;
    for (i = 0; i < size; i++)
    {
        A[i] = 2 * A[i];
    }
} // doubleElement

/**
 * Function: sumOfElement()
 *  sum up elements in array, return the sum
 *
 *  int A[], same as int* A, the passed array
 *  int size, the passed array's size
 *
 */
int sumOfElement(int *A, int size)
{
    int i, sum = 0;
    printf("SOE - Size of A = %d, size of A[0] = %d\n", sizeof(A), sizeof(A[0]));
    for (i = 0; i < size; i++)
    {
        sum += A[i]; // A[i] == *(A+i)
    }
    return sum;
} // sumOfElement

int main(int argc, char const *argv[])
{
    /* Arrays as function arguments */
    int A[] = {1, 2, 3, 4, 5};
    int size = sizeof(A) / sizeof(A[0]);   // get the size of the array
    int total = sumOfElement(&A[0], size); // &A[0] is address
    // call the function sumOfElement, the array passes by reference and the array's size
    printf("the sum of all element in the array: %d\n", total);
    printf("Main - Size of A = %d, size of A[0] = %d\n", sizeof(A), sizeof(A[0]));

    // call the function doubleElement()
    doubleElement(&A[0], size);
    for (int i = 0; i < size; i++)
    {
        printf("%d ", A[i]); // 2 4 6 8 10
    }

    return 0;
} // main
