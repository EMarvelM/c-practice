#include "main.h"

char * mergeAlternately(char * word1, char * word2){
  int len;
    
  len = strlen(word1);
  len += strlen(word2);
  
  char *merged = (char *)malloc(sizeof(char) * len + 1);

  int i, j = 0, k = 0;
  
  for(i = 0; i < len ; i++)
    {
     if ((i % 2) == 0)
       {
	 /* printf("word1 == %c\n", word1[k]); */
	merged[i] = word1[k];
	k++;
       }
     else if ((i % 2) != 0)
       {
	 /* printf("word2 == %c\n", word2[j]);  */
	merged[i] = word2[j];
	j++;
       }
    }

  return (merged);
}
