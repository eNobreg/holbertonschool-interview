#!/usr/bin/python3
"""
 Lockboxes Program solution
"""


def canUnlockAll(boxes):
    """
    Bool function to see if boxes can be opened
    """
    if not boxes:
        return False

    seen_boxes = {0}
    keys = [0]
    while(keys):
        c_key = keys.pop()
        for key in boxes[c_key]:
            if key not in seen_boxes:
                if (key <= len(boxes) - 1):
                    seen_boxes.add(key)
                    keys.append(key)

    return(len(seen_boxes) != len(boxes))
