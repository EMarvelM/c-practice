#include "main.h"

void _free()
{
  for (int k = 0; k < j; k++)
  {
    free(argv[k]);
  }
  free(argv);

}
