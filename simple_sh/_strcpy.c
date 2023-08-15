#include "main.h"

char *_strcpy(char *dest, const char *src)
{
    int i = 0;

    while(src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
    }
    /* adding a null character to terminate string */
    dest[i] = '\0';

    return(dest);
}