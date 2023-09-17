#include "sh.h"

/**
 * sh_prompt - write to the stdout
 * @disp: string to be writing to stdout
 *
 * Return: void.
*/
void sh_prompt(char *disp)
{
	int i = 0;
	int err_check;

	fflush(stdout); /*flush stdout before writing to avoid always offset 0*/

	while (disp[i] != '\0')
	{
		i++;
	}

	err_check = write(STDOUT_FILENO, disp, i);
	/* check for error */
	if (err_check == -1)
	{
		perror("Error writing to stdout");
		exit(-1);
	}
}
