#include "main.h"

/**
 * _strpars - Parse a string into array of arguments
 *
 * @j: Pointer to interger variable for track of array index.
 * @next_tok: Double pointer to the next token in the string.
 * @buffer: Double pointer points to string to be parsed/tokenized.
 * @delim: Delim that will be used for tokenization (when parsing).
 * @argv: Double pointer to the array to be fill with the tokens
 *
 * Return: On success the dynamically allocated array of argument.
 *		   on failure (malloc), returns NULL.
*/

char **_strpars(int *j, char **next_tok, char **buffer, const char *delim,
char ***argv)
{
	*j = 0; /* resetting the array index for loop */
	*next_tok = strtok(*buffer, delim);

	(*argv)[*j] = (char *)malloc(sizeof(char) * (_strlen(*next_tok) + 1));
	if ((*argv)[*j] == NULL)
	{
		perror("malloc");
		return (NULL);
	}

	_strcpy((*argv)[*j], *next_tok);
			printf("argv[%d] == %s\n", *j, (*argv)[*j]);

	while (*next_tok != NULL)
	{
		(*j)++;
		*next_tok = strtok(NULL, delim);

		if (*next_tok != NULL)
		{
			(*argv)[*j] = (char *)malloc(sizeof(char) * (_strlen(*next_tok) + 1));
			if ((*argv)[*j] == NULL)
			{
				perror("malloc");
				return (NULL);
			}

			_strcpy((*argv)[*j], *next_tok);
			printf("argv[%d] == %s\n", *j, (*argv)[*j]);
		}

	}

	return (*argv);
}
