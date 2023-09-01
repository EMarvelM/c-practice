#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int ini_line = 1;
    int line = 0 + ini_line;
    int xarata = 0;
    char ch;

    FILE *fp = NULL;
    if (fp)
    {
        printf("error occured!");
        exit (1);
    }

    fp = fopen("test.txt", "r");

    while((ch = fgetc(fp)) != EOF)
    {
        xarata++;
        if(ch == '\n')
        {
            line++;
        }
    }

    printf("\n\ntotal lines = %d", line);
    printf("\ntotal character = %d\n", xarata);

    return (0);
}