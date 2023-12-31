#include "sh.h"

/**
 * _count_tok - count number of tokens in the stream
 * to know amount of memory to allocate - read_cmd helper
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

	temp = (char *)malloc(sizeof(char) * (str_lenth + 1));
	check_malloc(temp);
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
    /*printf("\ntotal token == %ld\n", count);*/
    free(temp);
	return (count);
}


void check_malloc(char *tmp)
{
	if (!tmp)
	{
		perror("Malloc failed!");
		exit(1);
	}
}

void _free(char **argv)
{
	int j = 0;

	while (argv[j] != NULL)
	{
		free(argv[j]);
		j++;
	}
	free(argv[j]); /*free the NULL*/
	free(argv);
	printf("total == %d\n", j);
}