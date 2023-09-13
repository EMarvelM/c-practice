#include "sh.h"

int main(void)
{
	while(1) 
	{
		sh_prompt("Cisfun# ");
		read_cmd();

		/* isatty check here */
		cmd_mode();
	}
	return (0);
}

void cmd_mode(void)
{
	int mode;

	if ((mode = isatty(STDIN_FILENO)) == 0)
	{
		if (errno == EBADF)
		{
			perror("\nNo Valid fd!");
			exit(-1);
		}
		else if(errno == ENOTTY || errno == EINVAL)
		{
			perror("\nNo terminal!");
			exit(0);
		}
	}
}

void read_cmd(void)
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
			perror("\nEOF Reached!");
			exit(1);
		}
		else if (errno == EINVAL || errno == ENOMEM)
		{
			perror("\ngetline error!");
			exit(1);
		}
	}

	free(buffer);
}
