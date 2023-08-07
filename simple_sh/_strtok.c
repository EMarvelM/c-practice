#include <stdio.h>
#include <string.h>

int main()
{
        char *buffer;
        long unsigned int n = 0;
        char *del = " \n";
        char *argv;

        while(1)
        {
                /* Prompting the user in a loop*/
                printf("$ ");
                getline(&buffer, &n, stdin); /* stores each line using getline to var: buffer */

                char *token = strtok(buffer, del); /* makes buffer store only first argument v[0] */
                argv[0] = buffer;

                printf("buffer: %s\n", buffer);

                /* Stores the argument v[1,2, ...] of the user input */
                int i = 0;
                while (token != NULL)
                {
                    int count = 0;
                    i++;
                        token = strtok(NULL, del);
                            while (token)
                            {
                                count++;
                            }
                            
                        /* Stop printing the NULL token*/
                        if (token != NULL)
                        {
                            argv[i] = malloc(sizeof(char) * count);
                            strcpy(argv[i], token);
                            printf("token: %s\n", token);
                        }
                }
        }
}