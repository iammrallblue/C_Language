#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    // while loop = repeats a section of code possibly unlimited times.
    // WHILE some condition remains true
    // a while loop might not execute at all

    char name[25]; // declare a character array called "name" with a size of 25

    // printf("\nWhat is your name?: ");
    // fgets(name, 25, stdin);
    // name[strlen(name) - 1] = '\0';

    while (strlen(name) == 0) // while the length of "name" is 0 (i.e. empty input)
    {
        printf("You did not enter your name. "); // an empty input prompt
        printf("\nWhat is your name?: ");        // ask user to input
        fgets(name, 25, stdin);                  // read the user's input and store it in "name"
        name[strlen(name) - 1] = '\0';           // remove the newline character from "name"
    }

    printf("Hello %s", name);

    return 0;
}
