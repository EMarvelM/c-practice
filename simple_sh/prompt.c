#include <stdio.h>

int main(void)
{
    char *buffer;
    long unsigned int n = 0;
    //loop print "$ "
    // while(1)
    // {
        printf("$ ");
        getline(&buffer, &n, stdin);

        printf("%s", buffer);
    // }
}