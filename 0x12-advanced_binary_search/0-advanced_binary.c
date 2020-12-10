#include "search_algos.h"
int binary_helper(int *array, int left, int right, int value);

/**
 * advanced_binary - Uses the binary search algo to search array
 * @array: Array to search
 * @size: Size of the array
 * @value: Value to search
 * Return: -1 or the index
 */

int advanced_binary(int *array, size_t size, int value)
{
	size_t left = 0;
	size_t right = size - 1;

	if (array == NULL)
		return (-1);

	return (binary_helper(array, left, right, value));
}

/**
 * binary_helper - Recursive function
 * @array: Array to search
 * @left: Start of array
 * @right: End of array
 * @value: Value to find
 * Return: Index
 */
int binary_helper(int *array, int left, int right, int value)
{
	int mid = 0;
	int i = 0;

	if (left > right)
		return (-1);

	if (left <= right)
	{
		printf("Searching in array: ");
		for (i = left; i < right; i++)
			printf("%d, ", array[i]);
		printf("%d\n", array[i]);

		if (array[left] == value)
			return (left);

		mid = (left + right) / 2;

		if (array[mid] < value)
			return (binary_helper(array, mid + 1, right, value));
		return (binary_helper(array, left, mid, value));
	}
	return (-1);
}
