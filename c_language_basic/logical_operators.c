#include <stdio.h>
#include <stdbool.h>

int main(int argc, char const *argv[])
{
    /// logical operators = && (AND) checks if two conditions are true

    float temp = 25;
    bool sunny = false;

    if (temp >= 0 && temp <= 30 && sunny == true)
    {
        printf("\nThe weather is good!");
    }
    else
    {
        printf("\nThe weather is bad!");
    }

    // logical operators = || (OR) checks if at least one condition is true

    if (temp <= 0 || temp >= 30)
    {
        printf("\nThe weather is bad!");
    }
    // else if (temp >= 30)
    // {
    //     printf("\nThe weather is bad!");
    // }
    else
    {
        printf("\nThe weather is good!");
    }

    // logical operators = ! (NOT) reverses the state of a condition

    // bool sunny = true;
    // if (sunny == true)
    if (!sunny) // since sunny is false, !false is true, sunny == true
    {
        printf("\nIt's sunny outside!");
    }
    else
    {
        printf("\nIt's cloudy outside!");
    }

    return 0;
}
