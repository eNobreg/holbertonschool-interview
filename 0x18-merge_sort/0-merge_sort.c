#include <stdio.h>
#include "sort.h"
void mergesort(int i, int j, int *array, int *new_array);
void merge_arrays(int *arr, size_t mid, size_t na, size_t j, int *a);
void copy(int *arr, int *temp, size_t size);

/**
 * merge_sort - Merge sort function
 * @array: Array with values to sort
 * @size: Size of array
 * Return: Never
 */
void merge_sort(int *array, size_t size)
{
	int *new_array = malloc(sizeof(int) * size + 1);

	if (new_array == NULL)
		return;

	if (array == NULL || size < 2)
	{
		free(new_array);
		return;
	}
	mergesort(0, size, array, new_array);
	free(new_array);
}

/**
 * mergesort - Merge sort splitter function
 * @start: Start of the array
 * @end: End of the array
 * @array: Array to sort
 * @new_array: Working array
 * Return: Never
 */
void mergesort(int start, int end, int *array, int *new_array)
{
	size_t mid = 0;

	if (end - start < 2)
		return;

	mid = (start + end) / 2;
	mergesort(start, mid, array, new_array);
	mergesort(mid, end, array, new_array);

	merge_arrays(array, mid, end, start, new_array);
}

/**
 * merge_arrays - Merge arrays function
 * @arr: Array to sort
 * @mid: Midpoint of array
 * @end: Endpoint of the array
 * @start: Startpoit of the array
 * @temp: Temp working array
 * Return: Never
 */
void merge_arrays(int *arr, size_t mid, size_t end, size_t start, int *temp)
{
	size_t i = start, j = mid;
	size_t k = 0;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(&arr[start], mid - start);
	printf("[right]: ");
	print_array(&arr[mid], end - mid);

	for (k = start; k <= end; k++)
	{
		if (i < mid && (j >= end || arr[i] <= arr[j]))
		{
			temp[k] = arr[i];
			i++;
		}
		else
		{
			temp[k] = arr[j];
			j++;
		}
	}
	copy(arr, temp, end);
	printf("[Done]: ");
	print_array(&arr[start], end - start);
}

/**
 * copy - Copy arrays
 * @arr: Array to copy to
 * @temp: Array to copy from
 * @size: Size of the array
 * Return: Never
 */
void copy(int *arr, int *temp, size_t size)
{
	size_t i = 0;

	for (i = 0; i <= size; i++)
		arr[i] = temp[i];
}
