#include <stdio.h>

int main(void)
{
    char *buffer = NULL;
    long unsigned int n = 0;
    
    //loop printing "$ " and displaying user input
    while(1)
    {
        printf("$ ");
        getline(&buffer, &n, stdin);

        printf("%s", buffer);
    }
}