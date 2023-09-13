#include "sh.h"

/**
 * read_cmd - read for user input (stdin).
 *
 * Return: void
*/
char *read_cmd(void)
{
		/* getline */
	char *buffer = NULL;
	size_t n = 0;
	size_t char_n;

	char_n = getline(&buffer, &n, stdin);

	if (char_n == ((size_t)-1))
	{
		if (char_n == (size_t)EOF && errno == 0)
		{
			perror("\nEOF Reached!");
			exit(1);
		}
		else if (errno == EINVAL || errno == ENOMEM)
		{
			perror("\ngetline error!");
			exit(1);
		}
	}

	/* tokenization comes here!!! */

	return (buffer);
}
