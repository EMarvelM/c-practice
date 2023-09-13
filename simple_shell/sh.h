#ifndef SH_H
#define SH_H

#include <stdio.h> /* while testing (printf, getline, perror)*/
#include <unistd.h> /* write, isatty*/
#include <stdlib.h> /* exit */
#include <errno.h> /* ENIVAL, */


void sh_prompt(char *disp);
void read_cmd(void);
void cmd_mode(void); /* isatty check here */

#endif /* SH_H */