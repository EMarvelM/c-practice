#include "main.h"

int _prompt(char *display)
{
  int i = 0;
  
  /* count number of character */
  while(display[i])
    {
      i++;
    }

  /* print to stdout */
  write(STDOUT_FILENO, display, (i + 1));

  return (i);
}