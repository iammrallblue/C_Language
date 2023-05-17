#include <stdio.h>

int main()
{
    // switch = A more efficient alternative to using many "else if" statements
    // allows a value to be tested for equality against many cases

    char grade;

    printf("\nEnter a letter grade: ");
    scanf("%c", &grade);

    switch (grade)
    {
    case 'A':
        printf("perfect!\n");
        break;
    case 'B':
        printf("you did good!\n");
        break;
    case 'C':
        printf("you did okay!\n");
        break;
    case 'D':
        printf("At least it's not an F!\n");
        break;
    case 'F':
        printf("you failed!\n");
        break;
    default:
        printf("please enter only valid grades!\n");
    }

    // if (grade == 'A')
    // {
    //     printf("perfect!\n");
    // }
    // else if (grade == 'B')
    // {
    //     printf("you did good!\n");
    // }
    // else if (grade == 'C')
    // {
    //     printf("you did okay\n");
    // }
    // else if (grade == 'D')
    // {
    //     printf("At least it's not an F\n");
    // }
    // else if (grade == 'F')
    // {
    //     printf("You failed!\n");
    // }
    // else{
    //     printf("That's not a valid grade \n");
    // }

    return 0;
}