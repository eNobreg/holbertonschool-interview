#!/usr/bin/python3
"""
File to hold rain function
"""


def rain(walls):
    """
    Function to calculate amount of rain that can be held
    """
    arr_len = len(walls)
    i = 1
    saved_index = 0
    total = 0

    while (i < arr_len):
        if walls[i] >= walls[saved_index]:
            total += calculate_units(saved_index, i, walls)
            saved_index = i
        i += 1
    return total


def calculate_units(start, end, arr):
    """
    Calculate Units

    Takes in a start and end point and calculaes the units of rain in that area
    """
    total = 0
    for i in range(start, end):
        total += (arr[start] - arr[i])
    return total
