#include "sh.h"

/**
 * main - shell starting point
 *
 * Return: 0 at success.
*/
int main(int ac, char **agv, char **envp)
{
	char **argv = NULL;
	char **depath = NULL;
	char *ready4exc = NULL;

	(void)ac;
	(void)agv;
	while (1)
	{
		sh_prompt("Cisfun# ");
		argv = read_cmd();

		depath = pather(envp);
		ready4exc = cmd2path(argv, depath);

		/* isatty check here */
		cmd_mode();
		if (argv != NULL)
		{
			_free(argv);
		}
	}

	return (0);
}


char **pather(char **envp)
{
	int total_p = 1;
	int j, i;
	char *temp;
	int tok_len;
	char *test = NULL, **arr;

	j = 0;
	while (envp[j])
	{	
			
		if ((strncmp(envp[j], "PATH", 3) == 0))
		{
			temp = strdup(envp[j]);
			if (!temp)
			{
				perror("strdup failed");
				exit(0);
			}

			for (i = 0; temp[i] != '\0'; i++)
			{
				if (temp[i] == ':')
				{
					total_p++;
				}
			}
			arr = (char **)malloc(sizeof(char *) * (total_p + 1)); /*+1 for null*/
			if (arr == NULL)
			{
				perror("malloc failed");
			}

			for (i = 0; i < (total_p); i++)
			{
				if (i == 0)
				{
					test = strtok(temp, ":\n");
					if (test == NULL)
						return(arr);

					arr[i] = removePath(test);
					/*removePath(test);
					arr[i] = (char *)malloc(sizeof(char) * (strlen(test) + 1));*/
					
					if (arr[i] == NULL)
					{
						perror("malloc failed");
						exit (1);
					}
				}
				else
				{
					test = strtok(NULL, ":\n");
					arr[i] = (char *)malloc(sizeof(char) * (strlen(test) + 1));
					if (arr[i] == NULL)
					{
						perror("malloc failed");
						exit (1);
					}
					strcpy(arr[i], test);

				}
			}
			arr[i] = NULL;
		}
		j++;
	}

	return (arr);
}


char *removePath(char *path)
{
	int i = 0;
	int len;
	char *temp;

	if (!path)
	{
		return (NULL);
	}

	len = strlen(path);
	temp = (char *)malloc(sizeof(char) * (len - 4)); /*-5 for PATH=*/

	while(path[i])
	{
		if (i > 4)
		{
			temp[i - 5] = path[i];
		}
		i++;
	}
	return (temp);
}

char *cmd2path(char **argp, char **paths)
{

	int i = 0, j = 0, new_len = 0, count = 0;
	char **new_paths;

	if (argp[j][j] == '/')
	{
		if (!(access(argp[j], X_OK)))
		{
			printf("%s\n", argp[j]);
			return(argp[j]);
		}
		else
			return(NULL);
	}

	while (paths[count] != NULL)
	{
		count++;
	}

	new_paths = (char **)malloc(sizeof(char *) * (count + 1));/*adding 1 for null*/
	for (i = 0; paths[i] != NULL; i++)
	{
		new_len = (strlen(argp[j]) + strlen(paths[i]) + 2);/*adding 1 for '\0'*/
		new_paths[i] = (char *)malloc(sizeof(char) * new_len);
		strcpy(new_paths[i], paths[i]);
		strcat(new_paths[i], "/");
		strcat(new_paths[i], argp[j]);
	}
	for (; paths[j] != NULL; j++)
	{
		if(!(access(new_paths[j], X_OK)))
		{
			printf("%s\n", new_paths[j]);
			return (new_paths[j]);
		}
	}
	return (NULL);
}
