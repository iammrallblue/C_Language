#include <stdio.h>

int main()
{
    // format specifier % = defines and formats a type of data to be displayed
    // %c = character
    // %s = string (array of characters)
    // %f = float
    // %lf = double
    // %d = integer

    // %0.1 = decimal precision
    // %1 = minimum field width
    // %- = left align

    float item1 = 5.75;
    float item2 = 10.00;
    float item3 = 100.99;
    printf("Item 1: $%f", item1); // %f prints out 5.750000

    return 0;
}