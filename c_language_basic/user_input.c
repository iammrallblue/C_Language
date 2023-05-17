#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    char name[25]; // bytes, a format of string
    int age;

    printf("What's your name?\n");
    // &name, passing the address of the variable name to scanf() function
    // this allows scanf() function to write the input string into
    // the memory location pointed to by name.
    // scanf("%s", &name);
    fgets(name, 25, stdin);
    name[strlen(name) - 1] = '\0';

    printf("\nHow old are you?");
    scanf("%d", &age);

    printf("\nHello %s", name);
    printf("\nYou are %d years old", age);

    int x, y, z;
    printf("Enter two numbers: ");
    scanf("%d %d", &x, &y);
    z = x + y;
    printf("The sum of %d + %d = %d\n ", x, y, z);

    return 0;
}
