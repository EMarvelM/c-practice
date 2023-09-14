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
	size_t total_token = 0;
	size_t str_lenthh = 0;
	char *next_token = NULL;
	char **argp = NULL;

	total_token = _count_tok(buffer, delim); /*counting the number of tokens*/
    /*add one for the NULL pointer*/
	argp = (char **)malloc(sizeof(char *) * (total_token + (size_t)1));

	next_token = strtok(buffer, delim);
	if (!next_token)
	{
		perror("initiale token error");
		exit(1);
	}

	str_lenthh = _strlen(next_token);


	argp[j] = (char *)malloc(sizeof(char) * (str_lenthh + (size_t)1));
	strcpy(argp[j], next_token);

	while (next_token)
	{
		j++;
		next_token = strtok(NULL, delim);

		if (next_token != NULL)
		{
			str_lenthh = _strlen(next_token);

			argp[j] = (char *)malloc(sizeof(char) * (str_lenthh + (size_t)1));
			strcpy(argp[j], next_token); /*we dont wanna copy the NULL*/
		}
	}

	/* testing */
	/* printf("number of token == %d\n", total_token); */

    return(argp);
}
