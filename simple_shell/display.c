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

	while (disp[i] != '\0')
	{
		i++;
	}

	write(STDOUT_FILENO, disp, i);
}
