#include <stdio.h>

int main(int argc, char const *argv[])
{
    int age;

    printf("\nEnter your age: ");
    scanf("%d", &age);

    if (age >= 18)
    {
        printf("you are now signed up!");
    }
    else if (age == 0)
    {
        printf("you can't sign up!, You were just born!");
    }
    else if (age < 0)
    {
        printf("you have not been born yet!");
    }
    else
    {
        printf("you are too young to sign up!");
    }

    return 0;
}
