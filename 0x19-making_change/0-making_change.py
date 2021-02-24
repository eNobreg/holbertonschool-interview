#!/usr/bin/python3
"""
Module for making change function
"""


def makeChange(coins, total):
    """
    Making change function
    coins: List of coin values
    total: Total coins to meet
    Return: The lowest amount of coins to make total
    or -1
    """
    count = 0

    if total <= 0:
        return 0

    coins = sorted(coins, reverse=True)

    for coin in coins:
        while total >= coin:
            total -= coin
            count += 1

    if total > 0:
        return -1
    else:
        return count
