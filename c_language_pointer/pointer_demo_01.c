#include <stdio.h>

int main(int argc, char const *argv[])
{
    int a = 5;   // variable declaration
    int *p = &a; // p = the address of a
    // int *p = &a;             // the address of a, or p = &a
    printf("a = %d\n", a);   // a = 5
    *p = 12;                 // dereferencing, same as a = 12
    printf("p = %p\n", p);   //  p = &a the address of a
    printf("&p = %p\n", &p); // &p = the address of pointer p
    // printf("p = %x\n", p);
    printf("*p = %d\n", *p);           // *p = 12
    printf("a = %d\n", a);             // a = 12
    printf("&a = %p\n", (void *)(&a)); // p == &a, the address of a

    int b = 20;
    *p = b; // not pointer p pointed to new address, only assign the value of b to *p
    printf("b = %d\n", b);
    printf("*p = %d\n", b);
    printf("a = %d\n", a);

    p = &b; // ponter p repointed to the new addres 
    printf("p= %p\n", p);
    return 0;
} // main
