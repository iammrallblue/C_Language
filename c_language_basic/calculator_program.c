#include <stdio.h>

int main(int argc, char const *argv[])
{
    char operator;
    double num_1;
    double num_2;
    double result;

    printf("\nEnter an operater (+ - * /): ");
    scanf("%c", &operator);

    printf("\nEnter number 1: ");
    scanf("%lf", &num_1);

    printf("\nEnter number 2: ");
    scanf("%lf", &num_2);

    switch (operator)
    {
    case '+':
        result = num_1 + num_2;
        printf("\nresult: %.2lf", result);
        break;
    case '-':
        result = num_1 - num_2;
        printf("\nresult: %.2lf", result);
        break;
    case '*':
        result = num_1 * num_2;
        printf("\nresult: %.2lf", result);
        break;
    case '/':
        result = num_1 / num_2;
        printf("\nresult: %.2lf", result);
        break;
    default:
        printf("\nThe input operator is not valid.");
    }

    return 0;
}
