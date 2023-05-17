#include <stdio.h>

int main()
{
    int arr[5] = {10, 20, 30, 40, 50};
    int *ptr = arr;

    printf("Value of arr[0]: %d\n", arr[0]);
    printf("Address of arr[0]: %p\n", &arr[0]);
    printf("Value stored in ptr: %p\n", ptr);
    printf("Value pointed by ptr: %d\n", *ptr);

    // Incrementing the pointer to point to the next element
    ptr++;
    printf("Value pointed by ptr after increment: %d\n", *ptr);

    return 0;
}
