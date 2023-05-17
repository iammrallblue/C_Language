#include <stdio.h>

int main()
{
    // constant = fixed value that cannot be altered by the program during its execution
    const float PI = 3.14159;
    // PI = 420.69; // error, constant is read only
    printf("%f", PI);

    return 0;
} // main