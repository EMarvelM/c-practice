#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>

int main()
{	
	/* Prompt the user for an input */
	char *prompt = "#cisfun ";
	int prompt_len = 0;
	/* getline */
	char *buf = NULL;
	size_t n = 0;
	int char_read = 0;



	/* strlen for prompt */
	while (prompt[prompt_len] != '\0')
	{
		prompt_len++;
	}
	prompt_len++;

	/*prompting userf or input*/
	while(1)
	{
		write(1, prompt, prompt_len);
		char_read = getline(&buf, &n, stdin);

		int save_errono = errno;/*Avoiding infinite loop by resetting errno*/
		errno = 0;

		if (char_read == -1)
		{
			/* error ocurred during getline*/
			if (save_errono == EINVAL)
			{
				perror("Invalid argument");
			}
			/* used the Ctrl + D */
			else
			{
				perror("EOL detected");
			}
			break; /* breaking out of loop to allow free work*/
		}
	}

	/* Deallocation of memory*/
	free(buf);
	return (0);
}