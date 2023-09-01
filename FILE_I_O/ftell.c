#include <stdio.h>
#include <stdlib.h>

int main(void)
{
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
    fseek(fp, 6, SEEK_SET);

    file_offs = ftell(fp);

    printf("%ld", file_offs);

    fclose(fp);
    return (0);
}