#include <stdio.h>
#include <string.h>

int main()
{
        char *buffer;
        long unsigned int n = 0;
        char *del = " \n";

        while(1)
        {
                /* Prompting the user in a loop*/
                printf("$ ");
                getline(&buffer, &n, stdin); /* stores each line using getline to var: buffer */

                char *token = strtok(buffer, del); /* makes buffer store only first argument v[0] */

                printf("buffer: %s\n", buffer);

                /* Stores the argument v[1,2, ...] of the user input */
                while (token != NULL)
                {
                        token = strtok(NULL, del);

                        /* Stop printing the NULL token*/
                        if (token != NULL)
                        printf("token: %s\n", token);
                }
        }
}