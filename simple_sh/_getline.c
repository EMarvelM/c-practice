#include "main.h"

ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	fflush(stdout);

	int i = 0;

	if (*n < 0)
	{
		perror("getline failed!");
		return (1);
	}

	else if(*n == 0)
	{
		
		int size_byte = 3;
		*n = 1;

		*lineptr = (char *)malloc(sizeof(char) * size_byte);
		if (lineptr == NULL)
		{
			perror("malloc");
			return (-1);
		}

		char c;
		while((read(STDIN_FILENO, &c, *n)) == 1 && c != '\n')
		{
			(*lineptr)[i] = c;
			i++;
			*lineptr = (char *)realloc(*lineptr,  (sizeof(char) + (size_byte - 2)));
		}
		(*lineptr)[i] = '\n';
		(*lineptr)[i++] = '\0';

	}
	*n = i;


	return (*n);
}
