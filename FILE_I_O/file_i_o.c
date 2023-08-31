#include <stdio.h>
#include <stdarg.h>

/**
 * main - Entry point
 * 
 * Return: on success 0, or 1 on error
 * 
 * open, process, close
*/

int main(void)
{
    FILE *fp = fopen("filename.txt", "a");

    if (!fp)
    {
        return (1);
    }

    /* fprintf(fp, "marvel%d\n", 4); */

    fclose(fp);
    return (0);
}