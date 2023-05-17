#include <stdio.h>

int main()
{
    int num = 10;
    int *ptr = &num; // Declaring a pointer and storing the address of 'num' in it.

    printf("Value of num: %d\n", num);
    printf("Address of num: %p\n", &num);
    printf("Value stored in ptr: %p\n", ptr);
    printf("Value pointed by ptr: %d\n", *ptr);

    return 0;
}