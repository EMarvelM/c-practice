#include "main.h"
unsigned int ascii_mani(char c)
{
	int dec = (int) c;
	int ans = -1, rem = -1, j = 0;

	char *binary = (char *)malloc(sizeof(char) * 9);
	if (binary == NULL)
	{
		perror("Malloc failed!");
		exit(-1);
	}

	binary[8] = '\0';
	//for(int i = 0; binary[i] != '\0'; i++)
	int i = 0;
	while(i < 8)
	{
		binary[i] = 0 + '0';
		i++;
	}

	while ( dec > 0)
	{
		printf("dec = %d\n", dec);
		if (rem == -1)
		{
			rem = dec % 2;
			dec = dec / 2;
			binary[j] = (int) rem + '0';
		}
		else
		{
			if ((dec % 2) == 0)
			{
				if (rem == 0) binary[j] = 0 + '0';
				else
				{
					rem *= 10;
					binary[j] = 0 + '0';
				}
				dec = dec / 2;
			}
			
			else if ((dec % 2) == 1)
			{
				rem = (rem * 10) + 1;
				dec = dec / 2;
				binary[j] = 1 + '0';
			}
		}
		j++;
	}
	printf("binary == %s\n", binary);
	while(rem > 0)
	{
		if (ans == -1)
		{
			ans = 0;
			ans += rem % 10;
			rem /= 10;
		}
		else
		{
			if ((rem % 10) == 0)
			{
				ans *= 10;
				rem /= 10;
			}
			else
			{
				ans = (ans * 10) + 1;
				rem /= 10;
			}
		
		}
	}

	return (ans);
}
