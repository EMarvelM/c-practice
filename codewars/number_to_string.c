#include <stdio.h>
#include <stdlib.h>

char *number_to_string(int number); 

/**
 * main - Entry point
 *
 * Return: 0 on success
 */
int main(void)
{
	int num = 111;
	char *str;
	str = number_to_string(num);
	
	//if (str)
		//printf("string == %s", str);
}


char *number_to_string(int number) {

    //  <----  hajime!
	int i, rem, s = 1;
	int num = malloc(sizeof(int) * s);
	int siz = 0;

	for (i = 0; number > 0; i++)
	{
		rem = number % 10; /* get last digit */
		number = number / 10;
		num[i] = rem;
		num = realloc(num, sizeof(int) * ++s);
	}
	
	c = malloc(sizeof(char) * s + 1);

	siz = sizeof(num) / sizeof(int);
	for (i = 0; i < siz; i++)
	{
		c[i] siz - i;
	}
	return (c);
}

