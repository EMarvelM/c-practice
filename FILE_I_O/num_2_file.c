#include <stdio.h>
#include <stdlib.h>

/**
 * main - Entry point
 * 
 * Returns: 0 on success.
*/

int main(void)
{
	int nums;
	FILE *fp = NULL;

	fp = fopen("number.txt", "w+");
	if (!fp)
	{
		printf("error opening file");
		exit(1);
	}

	/* processing */

	do {
		printf("Enter a #(-1 to quit): ");
		scanf("%d", &nums);

		if (nums == -1)
			break;
		fprintf(fp ,"%d\n", nums);
	} while (nums != -1);



	fclose(fp);
	return (0);
}
