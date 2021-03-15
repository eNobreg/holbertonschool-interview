#!/usr/bin/python3
"""
Module containing the Island Perimter function and
helper functions if needed
"""


def island_perimeter(grid):
    """
    Get's the perimeter of an island defined by a
    2D array of 1s and 0s

    Returns the perimeter of the island
    """
    perimeter_sum = 0

    for j in range(0, len(grid)):
        for i in range(0, len(grid[j])):
            c = i
            if grid[j][i] == 1:
                perimeter = 4
                # Checks indexes above, below, next, and behind the
                # current array index
                try:
                    if j - 1 >= 0 and grid[j - 1][c] == 1:
                        perimeter -= 1
                    if c + 1 < len(grid[j]) and grid[j][c + 1] == 1:
                        perimeter -= 1
                    if c - 1 >= 0 and grid[j][c - 1] == 1:
                        perimeter -= 1
                    if j + 1 < len(grid) and grid[j + 1][c] == 1:
                        perimeter -= 1
                except IndexError:
                    pass
                perimeter_sum += perimeter
    return perimeter_sum
