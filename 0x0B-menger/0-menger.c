#include "menger.h"

int divide_sponge(int row, int col);

/**
 * menger - Print a menger square based on a level
 * @level: The level of menger sponge to print
 * Return: Nothing
 */
void menger(int level)
{
	int i, j, size;

	size = pow(3, level);

	if (level == 0)
	{
		putchar('#');
		return;
	}


	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			if (divide_sponge(i, j) == 1)
				putchar(' ');
			else
			{
				putchar('#');
			}
		}
		putchar('\n');
	}
}

/**
 * divide_sponge - Recursive function to detect if a space possible
 * @row: The row to check
 * @col: The col to check
 * Return: 1 if it could be a space, 0 if it couldn't
 */
int divide_sponge(int row, int col)
{
	int result = 0;

	if (row || col)
	{
		if (row % 3 == 1 && col % 3 == 1)
		{
			return (1);
		}
		else
		{
			result = divide_sponge(row / 3, col / 3);
		}
		if (result == 1)
			return (1);
	}
	return (0);
}
