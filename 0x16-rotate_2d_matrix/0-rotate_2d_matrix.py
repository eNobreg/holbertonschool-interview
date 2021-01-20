#!/usr/bin/python3

"""
Rotation module
"""


def rotate_2d_matrix(matrix):
    """
    Rotation function
    """

    N = len(matrix)
    column = N - 1

    for x in range(0, int(N / 2)):
        for y in range(x, column - x):
            temp = matrix[x][y]
            matrix[x][y] = matrix[y][column - x]
            matrix[y][column - x] = matrix[column - x][column - y]
            matrix[column - x][column - y] = matrix[column - y][x]
            matrix[column - y][x] = temp
