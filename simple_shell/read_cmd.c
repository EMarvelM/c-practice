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
	_tokenise(buffer, " \n");

	/* testing */
	/* printf("argv == %s\n", buffer); */

	return (buffer);
}


/**
 * _tokenise - tokenize the string in the buffer(stream)
 * @buffer: the buffer to tokenize
 * @delim: the delimeter for the string in the buffer
 *
 * Return: void.
*/
void _tokenise(char *buffer, char *delim)
{
	int total_token;
	char **argv

	total_token = _count_tok(buffer, delim);

	//TODO: allocate memory for argv
	//TODO: allocate memory for argv[]
	//TODO: parse tokens into argv[]
	//TODO: pass the argv to the execve

	/* testing */
	/* printf("number of token == %d\n", total_token); */
}


/**
 * _count_tok - count number of tokens in the stream
 * to know amount of memory to allocate
 * @buffer: the buffer to count
 * @delim: the delimeter for the string in the buffer
 *
 * Return: number of token count
*/
int _count_tok(char *buffer, char *delim)
{
	char *next_token = NULL;
	int count = 0;

	next_token = strtok(buffer, delim);
	count++;

	while (next_token)
	{
		next_token = strtok(NULL, delim);

		/* if the next next_token is NULL dont count */
		if (next_token != NULL)
		{
			count++;
		}
	}
	return (count);
}
