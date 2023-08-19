#include <stdio.h>
#include <string.h>

int main(int ac, char *argv[], char **envp)
{
    int n = 0;
    while (envp[n] != NULL)
    {
        if (strncmp(envp[n], "PATH=", (size_t)5) == 0)
        {
            printf("%s\n\n", envp[n]);
        }
        n++;
    }
}