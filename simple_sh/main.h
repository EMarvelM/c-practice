#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>

extern char **environ; /* To pass the environment to execve */

int _prompt(char *display);
int str_count(char *buffer, char *delim);
int _strlen(char *next_tok);
char *_strcpy(char *dest, const char *src);
char **_strpars(int *j, char **next_tok, char **buffer, const char *delim, char ***argv);
int _execve(const char *pathname, char *const argv[], char *const envp[]);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
int execute_external_command(const char *command, char *const argv[]);

#endif /* MAIN_H */