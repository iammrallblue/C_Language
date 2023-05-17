#include <stdio.h>

void printFibonacci(int n)
{
    static int n1 = 0, n2 = 1, n3;
    if (n > 0)
    {
        n3 = n1 + n2;
        n1 = n2;
        n2 = n3;
        printf("%d ", n3);
        printFibonacci(n - 1);
    }
}

int main()
{
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Fibonacci Series: ");
    printf("%d %d ", 0, 1);
    printFibonacci(n - 2);
    return 0;
}

// #include <stdio.h>

// // This function calculates and prints the nth fibonacci number
// void printFibonacci(int n)
// {
// // Initialize the first two elements of the fibonacci series
// int n1 = 0, n2 = 1, n3 = 0;

// // Check if n is greater than 0
// if (n > 0)
// {
//     // Calculate the nth fibonacci number
//     for (int i = 2; i <= n; i++)
//     {
//         n3 = n1 + n2;
//         n1 = n2;
//         n2 = n3;
//     }

//     // Print the nth fibonacci number
//     printf("%d\n", n3);
// }
// // If n is not greater than 0, print an error message
// else
// {
//     printf("Error: Invalid value of n\n");
// }
// }

// int main()
// {
// int n;
// printf("Enter the number of elements: ");
// scanf("%d", &n);

// // Call the function to print the nth fibonacci number
// printFibonacci(n);

// return 0;
// }