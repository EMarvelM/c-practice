#include "sh.h"

int main(void)
{

	 while(1) {
		sh_prompt("Cisfun# ");
		read_cmd();

		/* Test */
	}
	return (0);
}

void read_cmd(void)
{
		/* getline */
	char *buffer = NULL;
	size_t n = 0;
	size_t char_n;

	if ((char_n = getline(&buffer, &n, stdin)) == ((size_t)-1))
	{

		if (char_n == (size_t)EOF && errno == 0)
		{
			perror("EOF Reached!");
			exit(1);
		}
		else
		{
			perror("getline error!");
			exit(1);
		}
	}

	free(buffer);
}
