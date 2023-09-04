#include <stdio.h>
#include <string.h>

int main(int ac, char **argv)
{
    if (!strcmp(argv[1], "Marvel!"))
    {
        printf("Congratulations\n");
    }
    else
    {
        printf("Try Again! :)\n");
    }
    return (0);
}