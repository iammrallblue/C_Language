#include <stdio.h>
#include <ctype.h>

int main(int argc, char const *argv[])
{
    char unit;
    float temp;

    printf("\nIs the temperature in (F) or (C)?: ");
    scanf("%c", &unit);

    // convert input to uppercase
    unit = toupper(unit);

    // determine temperature based on the unit
    if (unit == 'C') // || unit == 'c'
    {
        // printf("The temp is currently in C");
        printf("\nEnter the temp in Celsius: ");
        scanf("%f", &temp);
        temp = (temp * 9 / 5) + 32;
        printf("\nThe temp in Fahrenheit is: %.1f", temp);
    }
    else if (unit == 'F') // || unit == 'f'
    {
        // printf("The temp is currently in F");
        printf("\nEnter the temp in Fahrenheit: ");
        scanf("%f", &temp);
        temp = ((temp - 32) * 5) / 9;
        printf("\nThe temp in Celsius is: %.1f", temp);
    }
    else
    {
        printf("\n %c is not a valid input. ", unit);
    }

    return 0;
}
