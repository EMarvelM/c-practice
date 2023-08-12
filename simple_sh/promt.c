#include <stdio.h>
#include <string.h>

int main()
{
	char *buffer;
	long unsigned int n = 0;
	char *del = " \n";

	while(1)
	{
		printf("$ ");
		getline(&buffer, &n, stdin);

		char *token = strtok(buffer, del);

		printf("buffer: %s\n", buffer);

		while (token != NULL)
		{
			token = strtok(NULL, del);
			if (token != NULL)
			printf("token: %s\n", token);
		}	
	}
}
