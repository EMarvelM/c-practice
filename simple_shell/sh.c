#include "sh.h"

/**
 * main - shell starting point
 *
 * Return: 0 at success.
*/
int main(void)
{
	char *buffer;

	while (1)
	{
		sh_prompt("Cisfun# ");
		buffer = read_cmd();

		/* isatty check here */
		cmd_mode();

		free(buffer);
	}

	return (0);
}
