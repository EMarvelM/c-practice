#include <stdio.h>
#include <stdarg.h>

/**
 * main - Entry point
 * 
 * Return: on success 0.
 * 
 * open, process, close
*/

int main(void)
{
    FILE *fp = fopen("filename.txt", "a");

    /* fprintf(fp, "marvel%d\n", 4); */

    fclose(fp);
    return (0);
}