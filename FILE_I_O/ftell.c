#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int file_offs;

    FILE *fp;
    fp = NULL;

    fp = fopen("test.txt", "r");
    if (!fp)
    {
        printf("error opening file");
        exit(1);
    }

    /* handling offset */

    file_offs = ftell(fp);

    printf("%d", file_offs);

    return (0);
}