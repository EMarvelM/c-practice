#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char chs[100];
    char ch;
    long int file_offs;

    FILE *fp;
    fp = NULL;

    fp = fopen("test.txt", "r");
    if (!fp)
    {
        printf("error opening file");
        exit(1);
    }

    /* handling offset */
    fseek(fp, 1, SEEK_SET);

    file_offs = ftell(fp);

    ch = fgetc(fp);

    printf("\nThe character '%c'", ch);
    printf(" is the %ld in the file\n", file_offs);

    /* practical use of fscanf */
    fscanf(fp, "%s", chs);
    printf("%s", chs);

    printf("\n\t%ld\n", ftell(fp));

    fclose(fp);
    return (0);
}