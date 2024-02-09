#include "main.h"

char findTheDifference(char* s, char* t) {
	/* Return null character if the string is NULL */
	if (!s && !t) return ('\0');
	else if (!s) return ('\0');
	else if (!t) return ('\0');

	/* initialize i and j for the loop */
	int i = 0, j = 0;

	for (i = 0; t[i] != '\0'; i++)
	{
		/* for every letter in the longer string `t` */
		for(j = 0; s[j] != '\0'; j++)
		{
			/* for every letter in the shortest string `s` */
			if (t[i] == s[j]) break;
				/*if they match, stop searching the particular t index*/
		}
		/*if particular index in t wasn't found in s then we got the new letter*/
		if (t[i] != s[j]) break;
	}
	return (t[i]); /* return the letter that was added to `t`*/
}