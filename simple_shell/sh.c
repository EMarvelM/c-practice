#include "sh.h"

/**
 * main - shell starting point
 *
 * Return: 0 at success.
*/
int main(void)
{
	while (1)
	{
		sh_prompt("Cisfun# ");
		read_cmd();

		/* isatty check here */
		cmd_mode();
	}
	return (0);
}
