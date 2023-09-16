#ifndef SH_H
#define SH_H

#include <stdio.h> /* while testing (printf, getline, perror)*/
#include <unistd.h> /* write, isatty*/
#include <stdlib.h> /* exit */
#include <errno.h> /* ENIVAL, */
#include <string.h> /* strtok */
#include <sys/types.h> /*off_t*/
#include <signal.h> /*signal*/
#include <stdint.h>

void sh_prompt(char *disp);
char **read_cmd(void);

 /* isatty check here */
void cmd_mode(void);

char **_tokenise(char *buffer, char *delim);

size_t _count_tok(char *buffer, char *delim);

size_t _strlen(const char *_string);

void _free(char **argv);


#endif /* SH_H */
