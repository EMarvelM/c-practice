#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * main - Entry Point
 * 
 * Return: 0 on success.
*/
int main(void)
{
    char *str = NULL;
    size_t n = 0;

    FILE *fp;
    fp = NULL;

    fp = fopen("number.txt", "w");
    if (fp == NULL)
    {
        printf("error opening file");
        exit(1);
    }

    printf("Enter a string: ");
    getline(&str, &n, stdin);

    printf("%s", str);
    fprintf(fp, "%s\n", str);

    free(str);
    fclose(fp);
    return (0);
}
