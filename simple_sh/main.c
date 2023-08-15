#include "main.h"

int main(int ac, char *agv, char **envp)
{
	size_t n = 0;
	char *buffer = NULL;
	/* tokenization */
	char *delim = " \n";
	int count_tok = 0, j = 0;
	char *next_tok = NULL;

	/* parsing */
	char **argv;

	while(1)
	{
		_prompt("$ ");
		getline(&buffer, &n, stdin);

		/* counting all arguments */
		count_tok = str_count(buffer, delim);
		argv = (char **)malloc(sizeof(char *) * count_tok);
		if (argv == NULL)
				perror("malloc allocation failed");

		/* parsing into argv*/
		_strpars(&j, &next_tok, &buffer, delim, &argv);

		_execve(buffer, argv, envp);

		/* Free allocated memory */
		for (int k = 0; k < j; k++)
		{
			free(argv[k]);
		}
		free(argv);

	}
	/* END WHILE LOOP */

	free(buffer);
	return (0);
}

/* EXECVE*/
int _execve(const char *pathname, char *const argv[], char *const envp[])
{

}


char **_strpars(int *j, char **next_tok, char **buffer, const char *delim, char ***argv)
{
		*j = 0; /* resetting the array index for loop */

		*next_tok = strtok(*buffer, delim);

		(*argv)[*j] = (char *)malloc(sizeof(char) * (_strlen(*next_tok) + 1));
		if ((*argv)[*j] == NULL)
				{
					perror("malloc");
					return(NULL);
				}

		_strcpy((*argv)[*j], *next_tok);
				printf("argv[%d] == %s\n", *j, (*argv)[*j]);

		while (*next_tok != NULL)
		{
			(*j)++;
			*next_tok = strtok(NULL, delim);

			/* printf("argv[%d] == %s\n", *j, *next_tok); */
					if (*next_tok != NULL)
					{
						(*argv)[*j] = (char *)malloc(sizeof(char) * (_strlen(*next_tok) + 1));
						if ((*argv)[*j] == NULL)
						{
							perror("malloc");
							return(NULL);
						}

						_strcpy((*argv)[*j], *next_tok);
						printf("argv[%d] == %s\n", *j, (*argv)[*j]);
					}

		}

		return (*argv);
}