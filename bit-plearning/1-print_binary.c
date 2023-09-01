#include "main.h"

/**
 * print_binary - print a number in binary formats
 * @n: the number to be converted
 *
 * Return: void
 */

void print_binary(unsigned long int n)
{
    int divid;
    int remd;

    if (n > 0)
    {    divid = n >> 1;

        /* modulus */
        remd = n - (divid << 1);

        if (divid > 0)
        {
            print_binary(divid);
        }

        printf("%d", remd);
    }

    else if (n == 0)
    {
        printf("%d", 0);
    }


    return;
}