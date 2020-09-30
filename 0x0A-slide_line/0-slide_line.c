#include "slide_line.h"


/**
 * slide_line - Slides the given array left or right with 2048 behavior
 * @line: The integer array to slide
 * @size: The Size of the given array
 * @direction: The direction to slide the array in (SLIDE_LEFT or SLIDE_RIGHT)
 * Return: 1 on success and 0 on failure
 */
int slide_line(int *line, size_t size, int direction)
{
	int digit_count = 0;

	digit_count = count_digits(line, size);

	if (direction == SLIDE_LEFT)
		return (left_slide(line, size));
	else if (direction == SLIDE_RIGHT)
		return (right_slide(line, digit_count, size));
	else
		return (0);
}

/**
 * count_digits - counts the amount of digits in given array
 * @line: Array
 * @size: Size of array
 * Return: Count of digits
 */
int count_digits(int *line, int size)
{
	int j = 0;
	int i = 0;

	for (i = 0; i < size; i++)
	{
		if (line[i] != 0)
		{
			j += 1;
		}
	}
	return (j);
}

/**
 * left_slide -Slides the given array to the left with 248 logic
 * @line: Array to slide
 * @size: Size of the array
 * Return: 1 on success 0 on failure
 */
int left_slide(int *line, size_t size)
{
	int new_array[1000];
	size_t i = 0;
	size_t j = 0;

	while (i < size)
	{
		new_array[i] = 0;
		i++;
	}

	for (i = 0; i < size; i++)
	{
		if (line[i] != 0)
		{
			new_array[j] = line[i];
			line[i] = 0;
			j++;
		}
	}

	for (i = 0; i < size; i++)
	{
		if (new_array[i] == new_array[i + 1] && new_array[i] != 0)
		{
			new_array[i] += new_array[i + 1];
			new_array[i + 1] = 0;
		}
	}
	copy_array(line, new_array, size, 1);
	return (1);
}

/**
 * right_slide -Slides the given array to the right
 * @line: Array to slide
 * @digits: Amount of digits in the array
 * @size: Size of the array
 * Return: 1 on success 0 on failure
 */
int right_slide(int *line, int digits, int size)
{
	int new_array[1000];
	int i = 0;
	size_t j = (size - digits);

	while (i < size)
	{
		new_array[i] = 0;
		i++;
	}

	for (i = 0; i < size; i++)
	{
		if (line[i] != 0)
		{
			new_array[j] = line[i];
			line[i] = 0;
			j++;
		}
	}

	for (i = size - 1; i >= 0; i--)
	{
		if (new_array[i] == new_array[i - 1] && new_array[i] != 0)
		{
			new_array[i] += new_array[i - 1];
			new_array[i - 1] = 0;
		}
	}
	copy_array(line, new_array, size, 0);
	return (1);
}

/**
 * copy_array - Copies an array based on the diection given
 * @original: Original array
 * @copy_array: Array containing the finalized digits
 * @size: Size of both arrays
 * @direction: Direction of the slide
 * Return: Nothing
 */
void copy_array(int *original, int *copy_array, size_t size, int direction)
{
	size_t i = 0;
	size_t j = 0;
	int digits = count_digits(copy_array, size);

	if (direction == 1)
	{
		for (i = 0; i < size; i++)
		{
			if (copy_array[i] != 0)
			{
				original[j] = copy_array[i];
				j += 1;
			}
		}
	}
	else if (direction == 0)
	{
		j = (size - digits);

		for (i = 0; i < size; i++)
		{
			if (copy_array[i] != 0)
			{
				original[j] = copy_array[i];
				j++;
			}
		}
	}
}
