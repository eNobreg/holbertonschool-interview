#!/usr/bin/python3
"""
File to hold rain function
"""


def rain(walls):
    """
    Function to calculate amount of rain that can be held
    """
    if walls is None:
        return 0
    arr_len = len(walls)
    i = 0
    saved_index = 0
    total = 0

    while (i < arr_len):
        if walls[i] >= walls[saved_index]:
            total += calculate_units(saved_index, i, walls)
            saved_index = i
        elif i == arr_len - 1:
            walls[saved_index] -= 1
            i = saved_index
        i += 1
    return total


def calculate_units(start, end, arr):
    """
    Calculate Units

    Takes in a start and end point and calculaes the units of rain in that area
    """
    total = 0
    for i in range(start, end):
        result = (arr[start] - arr[i])
        total += result
    return total
