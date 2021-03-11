#include "sort.h"


/**
 * getMax - Gets the max value in an array
 * @array: The array to search
 * @n: Length of the array
 * Return: The max value
 */
int getMax(int *array, int n)
{
	int max = array[0];
	int i = 0;

	for (i = 1; i < n; i++)
		if (array[i] > max)
			max = array[i];
	return (max);
}

/**
 * countingSort - The actual sorting of radix sort, seperates values into group
 * @arr: Array to sort
 * @n: Sive of the array
 * @exp: The current digit
 * Return: Nothing
 */
void countingSort(int *arr, int n, int exp)
{
		int *output = NULL;
		int i = 0;
		int count[10] = {0};

		output = malloc(sizeof(int) * n);
		if (output == NULL)
			return;

		for (i = 0; i < n; i++)
			count[(arr[i] / exp) % 10]++;
		for (i = 1; i < 10; i++)
			count[i] += count[i - 1];

		for (i = n - 1; i >= 0; i--)
		{
			output[count[(arr[i] / exp) % 10] - 1] = arr[i];
			count[(arr[i] / exp) % 10]--;
		}

		for (i = 0; i < n; i++)
			arr[i] = output[i];

		free(output);
		print_array(arr, n);
}

/**
 * radix_sort - Driver function for radix sort, gets max value in array
 * @array: Array to sort
 * @size: Size of the array
 * Return: Nothing
 */
void radix_sort(int *array, size_t size)
{
	int max = 0;
	int place = 0;

	if (!array || size < 2)
		return;

	max = getMax(array, size);

	for (place = 1; max / place > 0; place *= 10)
		countingSort(array, size, place);
}
