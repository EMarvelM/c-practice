#include "sh.h"

/**
 * main - shell starting point
 *
 * Return: 0 at success.
*/
int main(int ac, char **agv, char **envp)
{
	char **argv = NULL;

	(void)ac;
	(void)agv;
	while (1)
	{
		sh_prompt("Cisfun# ");
		argv = read_cmd();

		pather(envp);

		/* isatty check here */
		cmd_mode();
		if (argv != NULL)
		{
			_free(argv);
		}
	}

	return (0);
}
