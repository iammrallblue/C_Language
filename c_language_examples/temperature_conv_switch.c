#include <stdio.h>

double convert_temp(double init_value, int init_scale, int final_scale)
{

    double final_value;
    switch (init_scale)
    {
    case 1: // Celsius to Kelvin
        if (final_scale == 1)
        {
            final_value = init_value + 273.15;
        }
        else if (final_scale == 2)
        { // Celsius to Fahrenheit
            final_value = (init_scale * 9 / 5) + 32;
        }
        break;
    case 2:
        if (final_scale == 1) // Kelvin to Celsius
        {
            final_value = init_value - 273.15;
        }
        else if (final_scale == 2) // Kelvin to Fahrenheit
        {
            final_value = ((init_value - 273.15) * 9 / 5) + 32;
        }
        break;
    case 3:
        if (final_scale == 1) // Fahrenheit to Celsius
        {
            final_value = (init_value - 32) * 5 / 9;
        }
        else if (final_scale == 2) // Fahrenheit to kelvin
        {
            final_value = ((init_value - 32) * 5 / 9) + 273.15;
        }
        break;
    }

    return final_value;

} // convert_temp

int main(int argc, char const *argv[])
{
    int option;
    double init_value, final_value;
    while (1)
    {
        // main menu
        printf("\n0 - Exit\n");
        printf("1 - Convert from Celsius to Kelvin\n");
        printf("2 - Convert from Celsius to Fahrenheit\n");
        printf("3 - Convert from Kelvin to Fahrenheit\n");
        printf("4 - Convert from Kelvin to Celsius\n");
        printf("5 - Convert from Fahrenheit to Celsius\n");
        printf("6 - Convert from Fahrenheit to Kelvin\n");

        printf("Select a number: ");
        scanf("%d", &option); // save to the address of variable option
        if (!option)
        {
            printf("Ending program\n");
            return 0;
        }

        printf("Please enter the initial value: ");
        scanf("%lf", &init_value);

        switch (option)
        {
        case 1:
            final_value = convert_temp(init_value, 1, 1);
            printf("Valor em Kelvin: %.2lf", final_value);
            break;
        case 2:
            final_value = convert_temp(init_value, 1, 2);
            printf("Valor em Fahrenheit: %.2lf", final_value);
            break;
        case 3:
            final_value = convert_temp(init_value, 2, 1);
            printf("Valor em Celsius: %.2lf", final_value);
            break;
        case 4:
            final_value = convert_temp(init_value, 2, 2);
            printf("Valor em Fahrenheit: %.2lf", final_value);
            break;
        case 5:
            final_value = convert_temp(init_value, 3, 1);
            printf("Valor em Celsius: %.2lf", final_value);
            break;
        case 6:
            final_value = convert_temp(init_value, 3, 2);
            printf("Valor em kelvin: %.2lf", final_value);
            break;
        }
        printf("\n");
    }
    return 0;
}
