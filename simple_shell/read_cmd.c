#include "sh.h"

static char *buffer;

/**
 * read_cmd - read for user input (stdin).
 *
 * Return: void
*/
char **read_cmd(void)
{
		/* getline */
	size_t n = 0;
	size_t char_n;
	char **argv = NULL;

	buffer = NULL;


	signal(SIGINT, sigintHandler);

	char_n = getline(&buffer, &n, stdin);

	if (char_n == ((size_t)-1))
	{
		if (char_n == (size_t)EOF && errno == 0)
		{
			free(buffer);
			perror("\nEOF Reached!");
			exit(0);
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


/**
 * sigintHandler - signal call to this function and works on the
 * catch of a Ctrl + c
 * @signum: unused parameter in function
 * 
 * Return: void
*/
void sigintHandler(int signum)
{
	/*just decieving the standard c90 flag checker*/
	printf("working right\n");
	(void)signum;


	printf("freeing buffer");
	free (buffer);
	exit(1);
}
