#!/usr/bin/python3
"""
Module for UTF8
"""


def validUTF8(data):
    """
    Validate UTF8
    This uses numbers to validate if a character is UTF-8


    1-Byte = 0xxxxxxxx || Any number 0 -> 127

    Each folowing character must be followed by continuation bit(s)

    A correct continuation bit is 10xxxxxx = 128
    An incorrect continuation bit is 11xxxxxx = 192

    2-Byte = 110xxxxx || 192
    3-Byte = 1110xxxxx || 224
    4-Bytes = 11110xxx || 240

    """

    index = 0
    while index < len(data):
        leading_byte = data[index]

        if 0 <= leading_byte < 128:
            # If byte doesn't start with 0, 0xxxxxxx = valid 1xxxxxxxx = inval
            index += 1
        elif 128 <= leading_byte < 192:
            # If there is an invalid lead for 2 Bytes 110xxxxx = 192
            return False
        elif 192 <= leading_byte < 224:
            # If the leading byte is matches a 2 bit character
            # 110x is 192
            # 111x is 224
            if index + 1 < len(data) and 128 <= data[index + 1] < 192:
                # If the index is in range, and the next leading bit is correct
                index += 2
            else:
                return False
        elif 224 <= leading_byte < 240:
            # If the leading byte matches a 3 byte character
            # 224 is 1110xxxx
            # 240 is 1111xxxx
            if index + 2 < len(data)\
                and 128 <= data[index + 1] < 192\
                    and 128 <= data[index + 2] < 192:
                # If the index in range and the next two cont bits correct

                index += 3
            else:
                return False

        elif 240 <= leading_byte < 248:
            # If the leading byte matches a 4 byte character
            # 1111 0xxx is a valid character = 240
            # 1111 1xxx is invalid = 248
            if index + 3 < len(data)\
                and 128 <= data[index + 1] < 192\
                    and 128 <= data[index + 2] < 192\
                    and 128 <= data[index + 3] < 192:
                # If the index in range and the next three cont bits correct
                index += 3
            else:
                return False
        else:
            # Return false because all leading formats were invalid
            return False
    return True
