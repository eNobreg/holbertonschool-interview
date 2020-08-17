#include "sandpiles.h"

/**
 * sandpiles_sum - Takes in two 3x3 grids and sifts them till stable
 * @grid1: First grid to sift
 * @grid2: second grid to add
 * Return: None
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int is_stable = 0;

	/* Add grids together */
	add(grid1, grid2);
	is_stable = check_stability(grid1);

	/* Loop until grid is stable */
	while (is_stable == 0)
	{
		if (is_stable == 0)
		{
			print_grid(grid1);
			topple(grid1, grid2);
		}
		is_stable = check_stability(grid1);
	}
}

/**
 * topple - Topples the sandpile by checking available positions
 * @grid1: Grid to topple
 * @grid2: Grid to add values into
 * Return: Nothing
 */
void topple(int grid1[3][3], int grid2[3][3])
{
	int i = 0;
	int j = 0;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid1[i][j] > 3)
			{
				grid2[i][j] -= 4;
				if (i + 1 <= 2)
					grid2[i + 1][j] += 1;
				if (i - 1 >= 0)
					grid2[i - 1][j] += 1;
				if (j + 1 <= 2)
					grid2[i][j + 1] += 1;
				if (j - 1 >= 0)
					grid2[i][j - 1] += 1;
			}
		}
	}
	add(grid1, grid2);
}

/**
 * check_stability - Checks the stability of a pile: is stable if no positon > 3
 * @grid1: Pile to check
 * Return: Nothing
 */
int check_stability(int grid1[3][3])
{
	int i = 0;
	int j = 0;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid1[i][j] > 3)
				return (0);
		}
	}
	return (1);
}


/**
 * print_grid - Prints out a 2D array
 * @grid: Grid to print
 * Return: Nothing
 */
static void print_grid(int grid[3][3])
{
	int i, j;

	printf("=\n");
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}

/**
 * add - Adds sandpiles together
 * @grid1: First grid to add
 * @grid2: Second grid to add
 * Return: Nothing
 */
void add(int grid1[3][3], int grid2[3][3])
{
	int i = 0;
	int j = 0;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grid1[i][j] += grid2[i][j];
			grid2[i][j] = 0;
		}
	}
}
