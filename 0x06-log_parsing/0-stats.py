#!/usr/bin/python3
"""
The module for the log parsing script
"""
import sys


def print_log(file_size, status_codes):
    """
    Prints the logs of the input in the correct format
    Accepts a int file size, and a dictionary of status
    codes
    """
    print("File size: {}".format(total_size))

    for key, value in status_codes.items():
        if value != 0:
            print("{}: {}".format(key, value))


if __name__ == "__main__":
    total_size = 0
    i = 0

    status_codes = {
        "200": 0,
        "301": 0,
        "400": 0,
        "401": 0,
        "403": 0,
        "404": 0,
        "405": 0,
        "500": 0
    }
    try:
        for line in sys.stdin:
            if (i == 10):
                print("enter")
                print_log(total_size, status_codes)
                i = 0

            split_string = line.split(" ")

            status_code = split_string[7]
            status_codes[status_code] += 1

            file_size = split_string[8]
            file_size = int(file_size[:-2])
            total_size += file_size
            i += 1

    except KeyboardInterrupt:
        print_log(total_size, status_codes)
        raise

    print_log(total_size, status_codes)
