#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char ch;

    FILE *fp;
    fp = NULL;
        /* File pointer error checker */
    if (fp)
    {
        printf("error with file pointer");
        exit(1);
    }

    fp = fopen("test.txt", "r+");

    /* Processing the file */
    fseek(fp, 10, SEEK_SET);

    while ((ch = fgetc(fp)) != EOF)
    {
        printf("%c", ch);
    }

    fclose(fp);

    return (0);
}
