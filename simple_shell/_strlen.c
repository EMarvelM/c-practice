#include "sh.h"

/**
 * _strlen - calcucate the lenth of a string
 * @_string: string to count
 *
 * Return: total character count excluding '\0'
*/

size_t _strlen(const char *_string)
{
	size_t count = 0;

	while (_string[count])
	{
		if (_string[count])
			count++;
	}
	/*testing works :)*/
	/*printf("_strlen == %ld", count);*/

	return (count);
}
