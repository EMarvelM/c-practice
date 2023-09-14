#include "sh.h"

/**
 * _strlen - calcucate the lenth of a string
 * 
*/

size_t _strlen(const char *_string)
{
    size_t count = 0;

    while(_string[count] != '\0')
    {
        if (_string[count])
            count++;
    }
    /*testing works :)*/
    /*printf("_strlen == %d", count);*/

    return (count)
}