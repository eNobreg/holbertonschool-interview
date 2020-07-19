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
                seen_boxes.add(key)
                if (key <= len(boxes) - 1):
                	keys.append(key)

    for i in range(len(boxes)):
        if i not in seen_boxes:
            return False
    return(True)
