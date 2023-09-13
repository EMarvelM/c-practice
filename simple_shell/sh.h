#ifndef SH_H
#define SH_H

#include <stdio.h> /* while testing (printf, getline, perror)*/
#include <unistd.h> /* write, isatty*/
#include <stdlib.h> /* exit */
#include <errno.h> /* ENIVAL, */
#include <string.h> /* strtok */


void sh_prompt(char *disp);
char *read_cmd(void);

 /* isatty check here */
void cmd_mode(void);

void _tokenise(char *buffer, char *delim);

int _count_tok(char *buffer, char *delim);

#endif /* SH_H */
