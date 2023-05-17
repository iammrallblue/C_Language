#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    // char C[20] = "JOHN"; // length 4
    char C[] = "JOHN";
    int len = strlen(C);
    printf("the length of char array C: %d\n", len);

    return 0;
}

// int main(int argc, char const *argv[])
// {
//     /* Character arrays and pointers */
//     // char C[20]; // length 20
//     C[0] = 'J';
//     C[1] = 'O';
//     C[2] = 'H';
//     C[3] = 'N';
//     C[4] = '\0'; // with the null-terminated character '\0'
//     printf("%s", C); // result "JOHN"
//     return 0;
// }

// int main(int argc, char const *argv[])
// {
//     /* Character arrays and pointers */
//     char C[5]; // length 5
//     C[0] = 'J';
//     C[1] = 'O';
//     C[2] = 'H';
//     C[3] = 'N';
//     C[4] = '\0';     // with the null-terminated character '\0'
//     printf("%s", C); // result "JOHN"
//     return 0;
// } // main

// int main(int argc, char const *argv[])
// {
//     /* Character arrays and pointers */
//     char C[4]; // without '\0',
//     C[0] = 'J';
//     C[1] = 'O';
//     C[2] = 'H';
//     C[3] = 'N';
//     printf("%s", C); // result JOHN�?��
//     return 0;
// } // main
