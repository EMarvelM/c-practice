#include "sh.h"

/**
 * cmd_mode - checks for interactive mode (terminal).
 *
 * Return: void.
*/
void cmd_mode(void)
{
	int mode;

	mode = isatty(STDIN_FILENO);

	if (mode == 0)
	{
		if (errno == EBADF)
		{
			perror("\nNo Valid fd!");
			exit(-1);
		}
		else if (errno == ENOTTY || errno == EINVAL)
		{
			perror("\nNo terminal!");
			exit(0);
		}
	}
}
