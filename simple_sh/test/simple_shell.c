#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

int main()
{
        /* Prompt the user for an input */
        char *prompt = "#cisfun ";
        int prompt_len = 0;
        /* getline */
        char *buf = NULL;
        size_t n = 0;
        int char_read = 0;
        /* tokenization */
        char *delim = " \n";
        char *next_tok = NULL;
        /* parsing */
        char **argv;
        int i = 0, j = 0, argv_size = 1;


        /* strlen for prompt */
        while (prompt[prompt_len] != '\0')
        {
                prompt_len++;
        }
        prompt_len++;

        /*prompting userf or input*/
        while(1)
        {
                write(1, prompt, prompt_len);
                char_read = getline(&buf, &n, stdin);


                /* Parsing the command */
                next_tok = strtok(buf, delim);

                /* printf("token ->>: %s\n", buf); ---- testing for modified value of buf*/
                argv = (char **)malloc(sizeof(char *) * (argv_size + 1)); /* allocating for first command adding 1 for NULL pointer */      
                while (next_tok != NULL)
                {
                                /* determine strlen of tokens */
                        i = 0; /* reset i to correctly dtermine each token_len */
                        while (next_tok[i] != '\0')
                        {
                                i++;
                        }

                        /* memory allocation for tokens */
                        argv = (char **)realloc(argv, sizeof(char *) * (argv_size  + 1)); /* adding two, one for NULL*/
                        argv[j] = (char *)malloc(sizeof(char) * (i + 1));

                        /* printf("next token ->>: %s\n", next_tok); ----- testing for the modified value of next_tok */
                        strcpy(argv[j], next_tok);
//                      *argv[j] = next_tok; string copy not this
                        j++;
						next_tok = strtok(NULL, delim);
                }
                argv[j] = NULL; /* setting the last value of the array to null*/

                //TESTING
                int ch = 0;
                while(argv[ch] != NULL)
                {
                        printf("argve == %s\n", argv[ch]);
                        ch++;
                }

                /*Avoiding infinite loop by resetting errno*/
                int save_errono = errno;
                errno = 0;

                if (char_read == -1)
                {
                        /* error ocurred during getline*/
                        if (save_errono == EINVAL)
                        {
                                perror("Invalid argument");
                        }
                        /* used the Ctrl + D */
                        else
                        {
                                perror("EOL detected");
                        }
                        break; /* breaking out of loop to allow free work*/
                }

        }

        /* Deallocation of memory*/
        free(buf);
        free(argv);
        return (0);
}