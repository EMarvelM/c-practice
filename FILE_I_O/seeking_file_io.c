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

    fp = open(test.txt);
}