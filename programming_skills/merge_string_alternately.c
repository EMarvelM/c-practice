#include "main.h"

/**
 * mergeAlternately - combines two string together alternatively
 * @word1: the first string
 * @word2: the second string
 * return: the combination of both string
*/

char *mergeAlternately(char *word1, char *word2)
{
	/* return if either string is NULL or both*/
	if (!word1 && !word2)
		return (NULL);
	else if (!word1)
		return (word2);
	else if (!word2)
		return (word1);

	/* get the length of the total string*/
	int len;

	len = strlen(word1) + strlen(word2);

	/* allocate storage for the new string*/
	char *merged = (char *)malloc(sizeof(char) * (len + 1));

	if (merged == NULL)
	{
		perror("Malloc failed!");
		exit(-1);
	}

	int i, j = 0, k = 0;

	for (i = 0; i < len ; i++)
	{
		/*while both string are still not NULL*/
		if (word1[k] && word2[j])
		{
			if ((i % 2) == 0)
			{
				merged[i] = word1[k];
				k++;
			}
			else if ((i % 2) != 0)
			{
				merged[i] = word2[j];
				j++;
			}
		}
		/* when one string becomes NULL fill in the other */
		else
		{
			if (word1[k])
			{
				merged[i] = word1[k];
				k++;
			}
			else if (word2[j])
			{
				merged[i] = word2[j];
				j++;
			}
		}
	}
	merged[i] = '\0'; /* set the last character to the terminating char */

	return (merged); /* return the merged string */
}
