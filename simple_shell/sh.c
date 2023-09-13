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

