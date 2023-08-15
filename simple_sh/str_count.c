#include "main.h"

int str_count(char *buffer, char *delim)
{
  char *temp = NULL;
  char *next_tok = NULL;
  int count_tok = 0;
  
  /* counting the tokens */
    temp = strdup(buffer);
    next_tok = strtok(temp, delim);
    count_tok = 0; /* resetting count_tok */
    count_tok++;

    while(next_tok != NULL)
    {
      next_tok = strtok(NULL, delim);
      count_tok++;
    }

    free(temp); /* auto allocated by strdup()*/

  return (count_tok);
}