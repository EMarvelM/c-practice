#include <stdio.h>

int main(void)
{
    FILE *fp;
    fp = NULL;
        /* File pointer error checker */
    if (fp)
    {
        printf("error with file pointer");
        exit(1);
    }

    fp = open(fp);

    /* Processing the file */
    fseek(fp, 10, SEEK_SET);

    close(fp);
}