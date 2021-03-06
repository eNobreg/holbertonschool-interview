#!/usr/bin/python3
"""
The module for the log parsing script
"""
if __name__ == '__main__':
    import sys

    def print_log(file_size, status_codes):
        """
        Prints the logs of the input in the correct format
        Accepts a int file size, and a dictionary of status
        codes
        """
        print("File size: {}".format(total_size))

        for key, value in sorted(status_codes.items()):
            if value != 0:
                print("{}: {}".format(key, value))

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
            split_string = line.split()

            try:
                status_code = split_string[-2]
                if status_code in status_codes.keys():
                    status_codes[status_code] += 1
            except BaseException:
                pass

            try:
                file_size = split_string[-1]
                file_size = int(file_size)
                total_size += file_size
            except BaseException:
                pass

            i += 1

            if (i == 10):
                print_log(total_size, status_codes)
                i = 0

        print_log(total_size, status_codes)
    except KeyboardInterrupt:
        print_log(total_size, status_codes)
        raise
