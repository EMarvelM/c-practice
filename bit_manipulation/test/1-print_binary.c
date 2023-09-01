#include "main.h"

void print_binary(unsigned long int n)
{
    static int count = 0;

    if (n > 0)
    { 
        int result = 0;
        unsigned long int y = n;
        modu2(&n);

        result =  y - n - n;
        print_binary(n);

        printf("%d",result);
        count++;
        /* printf("the first value of %d is = %lu\n",result , y); */
    }
    else if (count == 0 && n == 0)
    {
        printf("%lu", n);
        count++;
    }
    return;
}

unsigned long int modu2(unsigned long int *digit)
{
    int mode = 1;
    
    *digit = (*digit >> mode);

    return (*digit);
}