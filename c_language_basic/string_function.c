#include <stdio.h>
#include <string.h>
#include <ctype.h>

/**
 * strlwr() function implementation:
 */
// char *strlwr(char *str)
// {
//     unsigned char *p = (unsigned char *)str;
//     while (*p)
//     {
//         *p = tolower((unsigned char)*p);
//         p++;
//     }

//     return str;
// } // strlwr

// char *strupr(char *str)
// {
//     unsigned char *p = (unsigned char *)str;
//     while (*p)
//     {
//         *p = toupper((unsigned char)*p);
//         p++;
//

//     return str;
// } // strupr

int main(int argc, char const *argv[])
{
    char str_1[] = "Bro";
    char str_2[] = "Code";

    // strlwr(str_1);        // converts a string to lowercase
    // strupr(str_2);        // converts a string to uppercase
    strcat(str_1, str_2); // appends string2 to end of string1
    // strncat(string1, string2, 1); // appends n characters from string2 to string1
    // strcpy (string1, string2); // copy string2 to string1
    // strncpy (string1, string2, 4); // copy n characters of string2 to string1

    // strset(string1, "?'); // sets all characters of a string to a given character
    // strnset(str_1, 'x', 1); // sets first n characters of a string to a given character
    // strrev (string1); // reverses a string

    int result = strlen(str_1);             // returns string length as int
    int result = strcmp(str_1, str_2);      // string compare all characters
    int result = strncmp(str_1, str_2, 1);  // string compare n characters
    int result = strcmpi(str_1, str_2);     // string compare all (ignore case)
    int result = strnicmp(str_1, str_1, 1); // string compare n characters (ignore case

    // printf("%s\n", str_1);

    // printf("%s\n", str_2);

    if (result == 0)
    {
        printf("These strings are the same. ");
    }
    else
    {
        printf("These strings are not the same. ");
    }

    printf("%s\n", str_1);

    return 0;
}
