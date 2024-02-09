#include "main.h"

char findTheDifference(char* s, char* t) {
	if (!s && !t) return ('\0');
	else if (!s) return ('\0');
	else if (!t) return ('\0');

	char temp;
	int i = 0, j = 0;

	for (i = 0; t[i] != '\0'; i++)
	{
		for(j = 0; s[j] != '\0'; j++)
		{
			if (t[i] == s[j]) break;
		}
		printf("Value i[%c] = %d\t", t[i], i);
		printf("Value j[%c] = %d\n", s[j], j);
		if (t[i] != s[j]) break;
	}
	return (t[i]);

	/* return (t[strlen(s)]); */
}