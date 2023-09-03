#include <stdio.h>
#include <stdlib.h>

/**
 * main - Entry point
 * 
 * Returns: 0 on success.
*/

int main(int argc, char **argv)
{
	int nums;
	int count = 0;
	FILE *fp = NULL;
	char *name;

	if (argv[1] != NULL)
		name = argv[1];
	else
		name = "default";

	fp = fopen(name, "w+");
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
		if (count != 0)
			fprintf(fp ,"\n");
		fprintf(fp ,"%d", nums);
		count++;
	} while (nums != -1);



	fclose(fp);
	return (0);
}
