#include "main.h"

int main(void)
{
  char *word1 = "mre";
  char *word2 = "avl";
  
  char *merged = mergeAlternately(word1, word2);
  printf("Merged == %s", merged);

  
  return (0);
}
