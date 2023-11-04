#include "main.h"

int main(int ac, char *argv[])
{
  if (ac != 2)
  {
    dprintf(2, "Usage: %s filename\n", argv[0]);
    exit(1);
  }

  char *filename = argv[1];

  FILE *fp = NULL;
  fp = fopen(filename, "r");
  if (fp == NULL)
  {
    perror("File not found!.");
    exit(-1);
  }

  char *buffer;
  size_t i = 0;
  char *next_t;
  while (getline(&buffer, &i, fp) != -1)
  {
    next_t = strtok(buffer, " \n");
    printf("Read: %s\n", next_t);
    while (next_t != NULL)
    {
      next_t = strtok(NULL, " \n");
      printf("Read: %s\n", next_t);
    }
  }
  return 0;
}