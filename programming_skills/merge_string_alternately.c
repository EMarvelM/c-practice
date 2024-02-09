#include "main.h"

char * mergeAlternately(char * word1, char * word2){
	if (!word1 && !word2)
		return (NULL);
	else if (!word1)
		return (word2);
	else if (!word2)
		return (word1);

	int len;

	len = strlen(word1);
	len += strlen(word2);

	char *merged = (char *)malloc(sizeof(char) * (len + 1));
	if (merged == NULL)
	{
		perror("Malloc failed!");
		exit(-1);
	}

	int i, j = 0, k = 0;

	for(i = 0; i < len ; i++)
		{
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
		merged[i] = '\0';

	return (merged);
}
