#include <stdio.h>

void birthday(char name[], int age)
{
    printf("\nHappy birthday dear %s ", name);
    printf("\nYou are %d years old!", age);
}

int main(int argc, char const *argv[])
{
    char name[] = "Bro";
    int age = 32;

    birthday(name, age);

    return 0;
}
