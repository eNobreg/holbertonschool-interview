#!/usr/bin/python3
""" Triangle Print """

def pascal_triangle(n):
    """ Making a matrix """
    matrix = []

    if n <= 0:
        return []

    for j in range(1, n + 1):
        new_list = []
        num = 1
        for i in range(1, j + 1):
            new_list.append(num)
            num = int(num * (j - i) / i + 0.1)
        matrix.append(new_list)
    return matrix