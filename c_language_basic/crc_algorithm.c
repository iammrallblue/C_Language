#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *xor1(char *x, char *y)
{
    char *result = (char *)malloc(strlen(y) + 1);

    int n = strlen(y);

    for (int i = 0; i < n; i++)
    {
        if (x[i] == y[i])
        {
            result[i] = '0';
        }
        else
        {
            result[i] = '1';
        }
    }

    result[n] = '\0';
    return result;
}

char *mod2div(char *dividend, char *divisor)
{
    int pick = strlen(divisor);
    char *tmp = (char *)malloc(pick + 1);
    strncpy(tmp, dividend, pick);
    tmp[pick] = '\0';

    int n = strlen(dividend);

    while (pick < n)
    {
        if (tmp[0] == '1')
        {
            strcpy(tmp, xor1(divisor, tmp));
            tmp[strlen(tmp)] = dividend[pick];
        }
        else
        {
            strcpy(tmp, xor1(strdup("000000000000000000000000"), tmp));
            tmp[strlen(tmp)] = dividend[pick];
        }
        pick += 1;
    }

    if (tmp[0] == '1')
    {
        strcpy(tmp, xor1(divisor, tmp));
    }
    else
    {
        strcpy(tmp, xor1(strdup("000000000000000000000000"), tmp));
    }

    return tmp;
}

void encodeData(char *data, char *key)
{
    int l_key = strlen(key);

    char *appended_data = (char *)malloc((strlen(data) + l_key) * sizeof(char));
    strcpy(appended_data, data);
    for (int i = 1; i < l_key; i++)
    {
        strcat(appended_data, "0");
    }

    char *remainder = mod2div(appended_data, key);
    char *codeword = (char *)malloc((strlen(data) + strlen(remainder) + 1) * sizeof(char));
    strcpy(codeword, data);
    strcat(codeword, remainder);
    printf("Remainder: %s\n", remainder);
    printf("Encoded Data (Data + Remainder): %s\n", codeword);
}

void receiver(char *data, char *key)
{
    char *currxor = mod2div(strncpy(strdup(data), 0, strlen(key)), key);
    int curr = strlen(key);
    int n = strlen(data);

    while (curr != n)
    {
        if (strlen(currxor) != strlen(key))
        {
            strncat(currxor, &data[curr + 1], 1);
        }
        else
        {
            currxor = mod2div(currxor, key);
        }
    }
    if (strlen(currxor) == strlen(key))
    {
        currxor = mod2div(currxor, key);
    }

    if (strstr(currxor, "1") != NULL)
    {
        printf("there is some error in data\n");
    }
    else
    {
        printf("correct message received.");
    }
}

int main(int argc, char const *argv[])
{
    char *data = "100100";
    char *key = "1101";
    printf("sender side...\n");
    encodeData(data, key);

    printf("\nReceiver side...");
    int size = strlen(data) + strlen(mod2div(strcat(strdup(data), strcat(strdup("0000000000000000"), key)), key));
    char *received_data = (char *)malloc(size * sizeof(char));
    strcpy(received_data, data);
    strcat(received_data, mod2div(strcat(strdup(data), strcat(strdup("0000000000000000"), key)), key));
    receiver(received_data, key);

    return 0;
}
