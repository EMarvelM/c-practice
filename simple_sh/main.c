#include "main.h"

/**
 * main - Code starts here
 *
 * @ac: number of command line argument
 * @agv: command line argument vector
 * @env: enviroment variables
 *
 * Return: - 0 on success, non-zero for failure
 *
*/

int main(int ac, char *agv, char **env)
{
	size_t n = 0, get_status;
	char *buffer = NULL;
	/* tokenization */
	char *delim = " \n";
	int count_tok = 0, j = 0;
	char *next_tok = NULL;
	/* parsing */
	char **argv;

	while (1)
	{
		_prompt("$ ");
		get_status = getline(&buffer, &n, stdin);
		
		if (get_status == -1)
		{
			if (feof(stdin))
			{
				perror("End of file");
				free(buffer);
				exit (EXIT_FAILURE);
			}
			else
			{
				perror("getline failed");
				free(buffer);
				exit (EXIT_FAILURE);
			}
		}

		/* counting all arguments */
		count_tok = str_count(buffer, delim);
		argv = (char **)malloc(sizeof(char *) * count_tok);
		if (argv == NULL)
		{
			perror("malloc failed");
			return (1); /* return non-zero for failure */
		}

		/* parsing into argv*/
		_strpars(&j, &next_tok, &buffer, delim, &argv);
		_execve(argv[0], argv, env);

		for (int k = 0; k < j; k++)
		{
			free(argv[k]);
		}
		free(argv);
	}

	free(buffer);
	return (0);
}

/**
 * _execve - execute a command
 *
 * @pathname: The path to the program to be executed.
 * @argv: The path to the program to be executed.
 * @envp: A vector of environment variables.
 *
 * Return: 0 on success, -1 on error
 *
*/
int _execve(const char *command, char *const argv[], char *const envp[])
{
	if (command == NULL || command[0] == '\0')
		return 1;

	if (execute_external_command(command, argv) == 0)
		return (0);

	/* Handle the case where the command is not found */
	printf("%s: command not found\n", command);
	return (1);
}

int execute_external_command(const char *command, char *const argv[])
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == 0)
	{
		execve(command, argv, environ);
		exit(EXIT_FAILURE); /* If execve fails */
	}
	else if (pid < 0)
	{
		perror("Fork error");
		exit(EXIT_FAILURE);
	}
	else
	{
		waitpid(pid, &status, 0);

	}

	return status;
}