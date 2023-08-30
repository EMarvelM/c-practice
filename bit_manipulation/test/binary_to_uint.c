#include "main.h"

/**
 * binary_to_uint - convert binary to positive number.
 * 
 * Return: the coverted number if a b is null or 0 when there is neither 1 or 0 in the string
*/

unsigned int binary_to_uint(const char *b)
{
	int track = 0;

	while(b[track] != '\0')
	{
		track++;
	}

	while(b[track] >= 0)
	{
		if (b[track] == 1)
		{
			printf("it is %d", b[track]);
		}
		else if (b[track] == 0)
		{
			printf("actually = %d", b[track]);
		}
		else{
			printf("not a digit");
		}
		track--;
	}
	/* printf("the value of track = %d\n", track); */
}