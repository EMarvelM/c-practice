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
	/* printf("argp == %s\n", buffer); */

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
	int j = 0;
	size_t total_token = 0;
	size_t str_lenthh = 0;
	char *next_token = NULL;
	char **argp = NULL;

	total_token = _count_tok(buffer, delim); /*counting the number of tokens*/
	argp = (char **)malloc(sizeof(char *) * (total_token + (size_t)1)); /*add one for the NULL pointer*/

	next_token = strtok(buffer, delim); /*having issues*/
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
	printf("\nwhen successfull\n");

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
size_t _count_tok(char *buffer, char *delim)
{
	char *temp = NULL;
	char *next_token = NULL;
	size_t count = 0;
	int str_lenth = 0;

	str_lenth = _strlen(buffer);

	temp = (char *)malloc(sizeof(char) * (str_lenth));
	strcpy(temp, buffer);

	next_token = strtok(temp, delim);
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
	/*testing*/
    printf("\ntotal token == %ld\n", count);

	return (count);
}
