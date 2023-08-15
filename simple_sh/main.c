#include "main.h"

int main(void)
{
  size_t n = 0;
  char *buffer = NULL;
  /* tokenization */
  char *delim = " \n";
  int count_tok = 0, j;
  char *next_tok = NULL;

  /* parsing */
  char **argv;
  
  while(1)
  {
    _prompt("$ ");
    getline(&buffer, &n, stdin);

    /* counting all arguments */
    count_tok = str_count(buffer, delim);
    argv = (char **)malloc(sizeof(char *) * count_tok);
            if (argv == NULL)
                perror("malloc");

    j = 0; //resetting the array index for loop

    next_tok = strtok(buffer, delim);
        
    argv[j] = (char *)malloc(sizeof(char) * (_strlen(next_tok) + 1));
            if (argv[j] == NULL)
                perror("malloc");

    strcpy(argv[j], next_tok);
        printf("argv[%d] == %s\n", j, argv[j]);
    
    while (next_tok != NULL)
      {
        j++;
        next_tok = strtok(NULL, delim);

        // printf("argv[%d] == %s\n", j, next_tok);
            if (next_tok != NULL)
            {
                    argv[j] = (char *)malloc(sizeof(char) * (_strlen(next_tok) + 1));
                    if (argv[j] == NULL)
                    {
                    perror("malloc");
                    }
                        strcpy(argv[j], next_tok);
                        printf("argv[%d] == %s\n", j, argv[j]);
            }

      }

  /* Free allocated memory */
  for (int k = 0; k < j; k++)
  {
    free(argv[k]);
  }
  free(argv);

  }
        /* END WHILE LOOP */
  

  free(buffer);
  return (0);
}