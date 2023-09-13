#include "sh.h"

void sh_prompt(char *disp)
{
	int i = 0;

	while (disp[i] != '\0')
	{
		i++;
	}

	write(STDOUT_FILENO, disp, i);	
}
