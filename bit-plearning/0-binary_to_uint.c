#include "main.h"

/**
 * binary_to_uint - converts a binary number to a decimal
 * @b: points to the collection of bits in a string
 *
 * Return: coverted number, or 0 if not 0s and 1s in string
 * and return 0 id b is NULL
 */

unsigned int binary_to_uint(const char *b)
{
	int i = 0;
	int pow;
	unsigned int result = 0;

	if (b == NULL)
	{
		return (0);
	}

	while (b[i] != '\0')
	{
		/* printf("%d ", i); */
		i++;
	}
	i--;

	for (pow = 0; i >= 0; )
	{   
		if (b[i] == '1')
		{
			result = result + (1 << pow);

			pow++;
		}
		else if (b[i] == '0')
		{
			pow++;
		}
		else
		{
		   return (0);
		}


		i--;
	}

	return (result);
}