#include "sandpiles.h"

void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
    int i = 0, j = 0;
    int is_stable = 0;

    /* Add grids together */
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            grid1[i][j] += grid2[i][j];
        }
    }

    /* Loop until grid is stable */
    while (is_stable == 0)
    {
        if (is_stable == 0)
        {
            print_grid(grid1);
            topple(grid1);
        }
        is_stable = check_stability(grid1);
    }
}

/**
 * 
 * 
 */
void topple(int grid1[3][3])
{
    int i = 0;
    int j = 0;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (grid1[i][j] >= 3)
            {
                grid1[i][j] -= 4;
                if (i + 1 <= 2)
                    grid1[i + 1][j] += 1;
                if (i - 1 >= 0)
                    grid1[i - 1][j] += 1;
                if (j + 1 <= 2)
                    grid1[i][j + 1] += 1;
                if (j - 1 >= 0)
                    grid1[i][j - 1] += 1;
            }
        }
    }
}

/**
 * 
 * 
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