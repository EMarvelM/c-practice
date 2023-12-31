#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int i = 0;
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

    while (i < 2)
    {
        /* while (!feof(fp)) // not a standard way of reading characters */
        while ((ch = fgetc(fp)) != EOF)
        {
            /* ch = fgetc(fp); */
            printf("%c", ch);
        }
        printf("\n\n");
        rewind(fp);
        i++;
    }

    fclose(fp);

    return (0);
}
