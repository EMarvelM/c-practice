#include <stdio.h>

void selectionSort(int arr[], int n);

int main(void)
{
	int n; /* Number of elements in the array */
	printf("Enter the number of elements: ");
	scanf("%d", &n);

	int arr[n]; /* Declare an array of size 'n' */

	/* Input elements from the user or initialize the array with predefined values */
	for (int i = 0; i < n; i++)
	{
		printf("Enter %d value: ", i + 1);
		scanf("%d", &arr[i]);
	}

	/* Call the bubbleSort function */

	/* Display the sorted array */
	printf("\nSorted array:");
	for (int j = 0; j < n; j++)
	{
		printf(" %d", arr[j]);
	}
	printf("\n");
	selectionSort(arr, n);

	return (0);
}

void selectionSort(int arr[], int n)
{
	/* Your sorting logic goes here */
	int i, j, min_idx;
	/*loop through the array*/
	for (i = 0; i < n; i++)
	{
		/*while looping through array, */
		for (j = i; j < n; j++)
		{
			/*find the smallest element in the array*/
			if (arr[j] < arr[j + 1])
			{
				min_idx = j;
			}

		}
		/*swap the smallest element with the first element*/
		j = arr[min_idx];
		arr[min_idx] = arr[i];
		arr[i] = j;

		printf("Sorted array:");
		for (int j = 0; j < n; j++)
		{
			printf(" %d", arr[j]);
		}
		printf("\n");
	}
	/*make sure not to go to start from the last swaped index at begining*/

}
