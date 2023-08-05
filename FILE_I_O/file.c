#include <stdio.h>
#include <stdlib.h>

int main (void)
{
    printf("Welcome!\n");
    FILE *fp = fopen("text.txt", "w");
    if (fp == NULL)
    {
        printf("File Opening Failed!\n");
        exit(1);
    }

    fprintf(fp, "Marvelous");
    fclose(fp);

}