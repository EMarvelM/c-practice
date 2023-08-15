#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

int _prompt(char *display);
int str_count(char *buffer, char *delim);
int _strlen(char *next_tok);
char *_strcpy(char *dest, const char *src);
char **_strpars(int *j, char **next_tok, char **buffer, const char *delim, char ***argv);

#endif /* MAIN_H */