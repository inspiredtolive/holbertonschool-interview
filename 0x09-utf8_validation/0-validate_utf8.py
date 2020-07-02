#!/usr/bin/python3
"""Provides a function to validate UTF-8."""


def validUTF8(data):
    """Determines if the data is valid UTF-8."""
    try:
        bytes(x & 0xff for x in data).decode()
        return True
    except UnicodeDecodeError:
        return False
