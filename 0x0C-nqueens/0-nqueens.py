#!/usr/bin/python3
import sys


def solveQueens(dimension, row, cells, results):
    """
    Dimension: The given dimensions of the chess board from STDIN
    Row: The current row we are solving for
    Cells: The current placement of queens in cells
    Results: The final results of answers
    """

    if (row == dimension):
        print(results)
    else:
        for column in range(0, dimension):
            cells.append(column)
            results.append([row, column])
            if (isValid(cells)):
                solveQueens(dimension, row + 1, cells, results)
            cells.pop()
            results.pop()


def isValid(cells):
    diff = 0
    rowId = len(cells) - 1
    for i in range(0, rowId):

        diff = cells[i] - cells[rowId]
        if (diff < 0):
            diff *= -1
        if (diff == 0 or diff == rowId - i):
            return False
    return True


def isInt(s):
    try:
        int(s)
        return True
    except ValueError:
        return False


def errorCheck(argv):
    if len(argv) < 2:
        print("Usage: nqueens N")
        return False

    n = argv[1]
    if not isInt(n):
        print("N must be a number")
        return False

    if int(n) < 4:
        print("N must be at least 4")
        return False

    return True


if not errorCheck(sys.argv):
    exit(1)

n = sys.argv[1]
results = []
solveQueens(int(n), 0, [], results)
