#include "sh.h"

/**
 * _tokenise - tokenize the string in the buffer(stream)
 * @buffer: the buffer to tokenize
 * @delim: the delimeter for the string in the buffer
 *
 * Return: void.
*/
char **_tokenise(char *buffer, char *delim)
{
	int j = 0;
	size_t total_token = 0, str_lenthh = 0;
	char *next_token = NULL;
	char **argp = NULL;

	total_token = _count_tok(buffer, delim); /*counting the number of tokens*/
	argp = (char **)malloc(sizeof(char *) * (total_token + (size_t)1));
	checkArgp(argp, buffer);

	next_token = strtok(buffer, delim);
	if (!next_token)
	{
		free(buffer);/*IF FIRST VALUE IS A NULL*/
		return (NULL);
	}

	str_lenthh = _strlen(next_token);
	argp[j] = (char *)malloc(sizeof(char) * (str_lenthh + (size_t)1));
	check_malloc(argp[j]);
	strcpy(argp[j], next_token);

	while (next_token)
	{
		j++;
		next_token = strtok(NULL, delim);

		if (next_token != NULL)
		{
			str_lenthh = _strlen(next_token);
			argp[j] = (char *)malloc(sizeof(char) * (str_lenthh + (size_t)1));
			check_malloc(argp[j]);
			strcpy(argp[j], next_token); /*we dont wanna copy the NULL*/
		}
		else if (next_token == NULL)
		argp[j] = NULL;
	}
	argp = testArgv(argp);

	free(buffer);
	return (argp);
}

/**
 * testArgv - prints the arguments in the **argp
 * @argp: string pointer array to print
 * To be Removed cause printf not suppored!
 *
 * Return: char **argp(string pointer array)
*/
char **testArgv(char **argp)
{
	int j;

	for (j = 0; argp[j] != NULL; j++)
	{
		printf("argp %d == %s\n", j, argp[j]);
	}

	return (argp);
}
