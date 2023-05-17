#include <stdio.h>

int main(int argc, char const *argv[])
{
    /* code */
    int a = 1025;
    int *p;
    p = &a;                                                 // pointer p = the address of a
    printf("size of integer is %d bytes \n", sizeof(int));  // 4 byts
    printf("pointer p, Address = %d, value = %d\n", p, *p); // p is address, *p is value
    // p + 1
    printf("p + 1, Address = %d, value = %d\n", p + 1, *(p + 1));
    // p + 1 address increases, *(p + 1) is the value in the address (p + 1)

    /* typecasting */
    char *p0;                                           // p0 is the char pointer
    p0 = (char *)p;                                     //  type casting int pointer p
    printf("size of char is %d byte \n", sizeof(char)); // char is 1 byte
    printf("Address = %d, value = %d\n", p0, *p0);
    printf("Address = %d, value = %d\n", p0 + 1, *(p0 + 1));
    // The char pointer p0 has same address with int pointer p,
    // *p0 has the value of a, but *p0 is char type, (casttyping)
    // why the value of *p0 is 1?
    // 1025 in 32-bit binary  0000 0000 0000 0000 0000 0100 0000 0001
    // typecasting made p0 to 0000 0001 (char is 1 byte or 8 bits)

    /* void pointer is a kind of generic pointer. */
    void *p1;
    p1 = p; // void pointer p1 has same addres with int pointer p
    printf("The void* p1, Address = %d\n", p1);
    printf("p= %d\n", p);
    return 0;
} // main
