#include <stdio.h>
#include <stdlib.h>

/*
This code is a temperature conversion program that allows the user to convert
a temperature from one scale to another, either from Celsius to Kelvin,
from Celsius to Fahrenheit, from Kelvin to Fahrenheit, from Kelvin to Celsius,
from Fahrenheit to Celsius, or from Fahrenheit to Kelvin.
The program runs in a loop, and the user can choose to exit
the program at any time by selecting the option 0.

The program uses a switch statement to determine the temperature conversion
that the user wants to perform and calls the convertTemp function to perform the conversion.
The convertTemp function takes three arguments: initValue, which is the initial
temperature value, initScale, which is the initial temperature scale,
and finalScale, which is the final temperature scale.

The convertTemp function uses a switch statement to determine the initial temperature
scale and perform the conversion based on the initScale and finalScale values.
If the initial scale is Celsius, the function performs the conversion to either
Kelvin or Fahrenheit. If the initial scale is Kelvin, the function performs
the conversion to either Celsius or Fahrenheit. If the initial scale is Fahrenheit,
the function performs the conversion to either Celsius or Kelvin.
The final temperature value is returned by the convertTemp function.

The main function displays the main menu, prompts the user for the conversion option
and initial temperature value, calls the convertTemp function to
perform the conversion, and displays the final temperature value.
*/

// Function that performs the conversion
double convertTemp(double initValue, int initScale, int finalScale)
{
    double finalValue;
    switch (initScale)
    {
    // Celsius
    case 1:
        // Celsius to Kelvin
        if (finalScale == 1)
        {
            finalValue = initValue + 273.15;
        }
        // Celsius to Fahrenheit
        else if (finalScale == 2)
        {
            finalValue = (initValue * 9 / 5) + 32;
        }
        break;
    case 2:
        // Kelvin to Celsius
        if (finalScale == 1)
        {
            finalValue = initValue - 273.15;
        }
        // Kelvin to Fahrenheit
        else if (finalScale == 2)
        {
            finalValue = ((initValue - 273.15) * 9 / 5) + 32;
        }
        break;
    case 3:
        // Fahrenheit to Celsius
        if (finalScale == 1)
        {
            finalValue = (initValue - 32) * 5 / 9;
        }
        // Fahrenheit to Kelvin
        else if (finalScale == 2)
        {
            finalValue = ((initValue - 32) * 5 / 9) + 273, 15;
        }
        break;
    }
    return finalValue;
}

int main()
{
    int option;
    double initialValue, finalValue;
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
        scanf("%d", &option);
        if (!option)
        {
            printf("Ending program\n");
            return 0;
        }

        printf("Please enter the initial value: ");
        scanf("%lf", &initialValue);

        switch (option)
        {
        case 1:
            finalValue = convertTemp(initialValue, 1, 1);
            printf("Valor em Kelvin: %.2lf", finalValue);
            break;
        case 2:
            finalValue = convertTemp(initialValue, 1, 2);
            printf("Valor em Fahrenheit: %.2lf", finalValue);
            break;
        case 3:
            finalValue = convertTemp(initialValue, 2, 1);
            printf("Valor em Celsius: %.2lf", finalValue);
            break;
        case 4:
            finalValue = convertTemp(initialValue, 2, 2);
            printf("Valor em Fahrenheit: %.2lf", finalValue);
            break;
        case 5:
            finalValue = convertTemp(initialValue, 3, 1);
            printf("Valor em Celsius: %.2lf", finalValue);
            break;
        case 6:
            finalValue = convertTemp(initialValue, 3, 1);
            printf("Valor em Kelvin: %.2lf", finalValue);
            break;
        }
        printf("\n");
    }

    return 0;
}