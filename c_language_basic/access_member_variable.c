#include <stdio.h>
#include <stdlib.h>

struct MyStruct
{
    int x;
};

int main(int argc, char const *argv[])
{
    struct MyStruct *ptr = malloc(sizeof(struct MyStruct));
    ptr->x = 5;

    printf("x = %d", ptr->x); // print out value
    return 0;
} // main
