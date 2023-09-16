#include "sh.h"

/**
 * read_cmd - read for user input (stdin).
 *
 * Return: void
*/
char **read_cmd(void)
{
		/* getline */
	char *buffer = NULL;
	size_t n = 0;
	size_t char_n;
	char **argv = NULL;
	uintptr_t sign;
	static int sign_c = 0;


	char_n = getline(&buffer, &n, stdin);

	/*make sure signal is called once throughout the program*/
	sign_c++;
	if (sign_c == 0)
	sign = (uintptr_t) signal(SIGINT, sigintHandler);

	/*free if Ctrl + C*/
	if (sign == SIGINT)
	{
		free (buffer);
		exit(0);
	}


	if (char_n == ((size_t)-1))
	{
		if (char_n == (size_t)EOF && errno == 0)
		{
			free(buffer);
			perror("\nEOF Reached!");
			exit(1);
		}
		else if (errno == EINVAL || errno == ENOMEM)
		{
			free(buffer);
			perror("\ngetline error!");
			exit(1);
		}
	}


	/* tokenization comes here!!! */
	argv = _tokenise(buffer, " \n");

	return (argv);
}

void sigintHandler(int signum)
{
	/*just decieving the standard c90 flag checker*/
	signum++;
	signum--;
}
