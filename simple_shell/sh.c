#include "sh.h"

/**
 * main - shell starting point
 *
 * Return: 0 at success.
*/
int main(void)
{
	char **argv = NULL;

	while (1)
	{
		sh_prompt("Cisfun# ");
		argv = read_cmd();

		/* isatty check here */
		cmd_mode();
		free(argv);
	}

	return (0);
}
