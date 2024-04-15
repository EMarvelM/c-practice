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
	int num = 999;
	char *str;
	str = number_to_string(num);
	
	if (str)
		printf("string == %s", str);
}


char *number_to_string(int number) {

    //  <----  hajime!
	int i, rem, s = 1;
	int *num = malloc(sizeof(int) * s);
	int siz = 0;
	char *c = NULL;

	for (i = 0; number > 0; i++)
	{
		rem = number % 10; /* get last digit */
		number = number / 10;
		num[i] = rem;
		/* verbose  printf("s = %d\n", s); */
		num = realloc(num, sizeof(int) * ++s);
	}
	c = malloc(sizeof(char) * s);
	s--;

	for (i = 0; i < s; i++) { printf("%d", num[i]); }
	printf("\n");

	for (i = 0; i < s; i++)
	{
		c[i] = 48 + num[s - (i + 1)];
	}
	c[i] = '\0';
	return (c);
}

