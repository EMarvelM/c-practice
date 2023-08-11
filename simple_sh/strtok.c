#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
        char *buffer = NULL;
        size_t n = 0;
        char *del = " \n";
        char **argv = NULL;

        while(1)
        {
            int argc = 0;
            
                /* Prompting the user in a loop*/
                printf("$ ");
                getline(&buffer, &n, stdin); /* stores each line using getline to var: buffer */


            argv = (char **)malloc(sizeof(char *) * (argc +1));

                char *token = strtok(buffer, del); /* makes buffer store only first argument v[0] */
                //argv[0] = buffer;  /* Not accepted */

                printf("buffer: %s\n", buffer);

                /* Stores the argument v[1,2, ...] of the user input */
                int i = 0;
                while (token != NULL)
                {
                    argc++;
                    int count = 0;
                    i++;
                        token = strtok(NULL, del);
                        argv[i] = (char *)malloc(strlen(token)+1);
                            while (token)
                            {
                                count++;
                            }
                            
                        /* Stop printing the NULL token*/
                        if (token != NULL)
                        {
                            /* parsing each token to a allocated memory as arguments */
                            /* argv[i] = (char *)malloc(sizeof(char) * count); */
                            strcpy(argv[i], token);
                            printf("token: %s\n", token);
                        }
                }
        }
}
