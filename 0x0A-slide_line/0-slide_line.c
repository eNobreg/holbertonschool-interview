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
    int new_array[size];
    int i = 0;
    int digit_count = 0;

    digit_count = count_digits(line, direction, size);


    
    return (0);
}

int count_digits(int* line, int direction, int size)
{
    int j = 0;
    for (int i = 0; i < size; i++)
    {
        if (line[i] != 0)
        {
            j += 1;
        }

    }
    return (j);
}