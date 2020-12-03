#include "sort.h"

void convert_to_heap(int *array, size_t size);
void sort(int *arr, size_t start, size_t end, size_t size);
void swap(int *arr, size_t size, int *first, int *second);



/**
 * heap_sort - Driver Function
 * @array: Array to sort
 * @size: Size of the array
 * Return: Nothing
 */
void heap_sort(int *array, size_t size)
{
	size_t last_index;

	if (!array || size < 2)
		return;

	last_index = size - 1;

	/* Moves the largest valu to the root of the array */
	convert_to_heap(array, size);

	while (last_index > 0)
	{
		swap(array, size, &array[last_index], &array[0]);
		last_index--;
		sort(array, 0, last_index, size);
	}
}

/**
 * convert_to_heap - converts an array to the heap format
 * @arr: Array to sort
 * @size: Size of the array
 * Return: Nothing
 */
void convert_to_heap(int *arr, size_t size)
{
	int start_index;

	start_index = (size / 2) - 1;

	while (start_index >= 0)
	{
		sort(arr, start_index, size - 1, size);
		start_index--;
	}
}

/**
 * swap - swaps the data at two points in memory for the array
 * @arr: Array to print
 * @size: Size of the array
 * @first: First node to swap
 * @second: Second node to wap
 * Return: Noothing
 */
void swap(int *arr, size_t size, int *first, int *second)
{
	int store;

	store = *first;
	*first = *second;
	*second = store;
	print_array(arr, size);

}

/**
 * sort - Main logicof the program, tells where to put each number
 * @arr: Array to sort
 * @start: Starting index
 * @end: End index
 * @size: Size of the array
 * Return: Nothing
 */

void sort(int *arr, size_t start, size_t end, size_t size)
{
	size_t save;
	size_t left;
	size_t right;
	size_t swap_var;

	save = start;

	while ((save * 2) + 1 <= end)
	{
		left = (save * 2) + 1;
		swap_var = save;

		if (left < size && arr[swap_var] < arr[left])
			swap_var = left;

		if (left + 1 <= end)
		{
			right = left + 1;
			if (arr[swap_var] < arr[right])
			{
				swap_var = right;
			}
		}
		if (swap_var != save)
		{
			swap(arr, size, &arr[save], &arr[swap_var]);
			save = swap_var;
		}
		else
			return;
	}
}
