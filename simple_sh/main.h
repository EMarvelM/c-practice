#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int _prompt(char *display);
int str_count(char *buffer, char *delim);
int _strlen(char *next_tok);
char *_strcpy(char *dest, const char *src);

#endif /* MAIN_H */