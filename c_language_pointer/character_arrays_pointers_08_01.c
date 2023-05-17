#include <stdio.h>
#include <string.h>

void print(const char *C) // char *C is a pointer which pointed to the array C in main function
{
    while (*C != '\0')
    {
        printf("%c", *C);
        C++; // char pointer increased
    }
    printf("\n");

} // print

int main(int argc, char const *argv[])
{
    char C[20] = "HELLO."; // string gets stored in the space for array
    // char *C = "HELLO."; // string gets stored as compile time constant
    // C[0] = 'A'; // compile error, if using char *C;

    // call the print() function to pass array C
    print(C);
    return 0;
} // main

// void printChar(char *C)
// {
//     int i = 0;
//     while (C[i] != '\0') // while loop ended at the the '\0'
//     {
//         printf("%c", C[i]);
//         i++;
//     } // while
//     printf("\n");

// } // printChar
// int main(int argc, char const *argv[])
// {
//     char C[20] = "HELLO, Char Array.";
//     // call the function printChar()
//     printChar(C);
//     return 0;
// } // main
