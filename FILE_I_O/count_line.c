#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int ini_line = 1;
    int count = 0 + ini_line;
    char ch;

    FILE *fp = NULL;
    if (fp)
    {
        printf("error occured!");
        exit (1);
    }

    fp = fopen("create_file.c", "r");

    while((ch = fgetc(fp)) != EOF)
    {
        if(ch == '\n')
        {
            count++;
        }
    }

    printf("total lines = %d", count);

    return (0);
}