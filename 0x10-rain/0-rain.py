#!/usr/bin/python3
"""Provides rain() function."""


def rain(walls):
    """Calculates the amount of rain collected between walls."""
    i, j = 0, len(walls) - 1
    lmax = rmax = res = 0
    while i < j:
        if walls[j] > walls[i]:
            if walls[i] > lmax:
                lmax = walls[i]
            else:
                res += lmax - walls[i]
            i += 1
        else:
            if walls[j] > rmax:
                rmax = walls[j]
            else:
                res += rmax - walls[j]
            j -= 1
    return res
