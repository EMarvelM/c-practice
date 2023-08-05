#include <stdio.h>

int main (void)
{
    FILE *fp = fopen(text.txt);
    if (fp == NULL)
    {
        printf("File Opening Failed!\n");
        exit(1);
    }

    fprintf(fp, "Marvelous");
    fclose(fp);

}