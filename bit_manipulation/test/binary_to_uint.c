#include "main.h"

/**
 * binary_to_uint - convert binary to positive number.
 * 
 * Return: the coverted number if a b is null or 0 when there is neither 1 or 0 in the string
*/

unsigned int binary_to_uint(const char *b)
{
    int i = 0;
    int j = 1;
    int value = 1;
    if (b[1] == '0')
    {
        value = 0;
    }
    while (b)
    {
        if (b[i] == '1' || b[i] == '0')
        {
            if (b[i] == '1')
            {
                value += 1 * j;
                j *= 2;
            }
            else if (b[i] == '0')
            {
                j *= 2;
            }

        }

        else
        {
            return 0;
        }
        i++;
    }
    return (value);
}