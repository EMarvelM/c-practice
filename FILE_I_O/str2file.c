#include <stdio.h>
#include <stdlib.h>

/**
 * main - Entry Point
 * 
 * Return: 0 on success.
*/
int main(void)
{
    char *str = NULL;

    FILE *fp;
    fp = NULL;

    fp = fopen("number.txt", "w");
    if (fp == NULL)
    {
        printf("error opening file");
        exit(1);
    }

    printf("Enter a string: ");
    scanf("%s", str);

    fprintf(fp, "%s\n", str);

    fclose(fp);
    return (0);
}
