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


