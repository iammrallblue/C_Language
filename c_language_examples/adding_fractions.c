#include <stdio.h>

int main(int argc, char const *argv[])
{
    int numerator_1;
    int numerator_2;
    int denominator_1;
    int denominator_2;
    int numerator_result;
    int denominator_result;

    printf("Enter 1st numerator: ");
    scanf("%d", &numerator_1);

    // printf("numerator_1 = %d\n", numerator_1);

    printf("Enter 1st denominator: ");
    scanf("%d", &denominator_1);

    printf("Enter 2nd numerator: ");
    scanf("%d", &numerator_2);

    printf("Enter 2nd denominator: ");
    scanf("%d", &denominator_2);

    if (denominator_1 == denominator_2)
    {
        numerator_result = numerator_1 + numerator_2;
        denominator_result = denominator_1;
    }
    else
    {
        numerator_result = (numerator_1 * denominator_2) + (numerator_2 * denominator_1);
        denominator_result = denominator_1 * denominator_2;
    }

    printf("The result of %d/%d + %d/%d is: %d/%d\n", numerator_1, denominator_1, numerator_2, denominator_2, numerator_result, denominator_result);

    return 0;
}
