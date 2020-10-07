#include "menger.h"

void menger(int level)
{
    int i, j;
    int index_i = 0;
    int index_j = 0;
    int scale = 0;
    int size = 0;
    char level1[3][3] = {
		{'#', '#', '#'},
		{'#', ' ', '#'},
		{'#', '#', '#'}
	};
    

    size = pow(3, level);
    scale = size / 3;



    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            index_i = i / scale;
            index_j = j / scale;

            if(level1[index_i][index_j] == ' ')
                putchar(' ');
            else if (i % 3 == 1 && j % 3 == 1)
                putchar(' ');
            else
            {
                putchar('#');
            }
        }
        putchar('\n');
    }
}
