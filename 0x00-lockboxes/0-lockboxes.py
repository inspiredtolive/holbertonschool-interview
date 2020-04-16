#!/usr/bin/python3


def canUnlockAll(boxes):
    unlocked = None
    unopened = set(range(0, len(boxes)))
    keys = {0}
    while keys:
        key = keys.pop()
        if key in unopened:
            unopened.remove(key)
            keys.update(boxes[key])
    if unopened:
            return False
    return True
