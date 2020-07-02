#!/usr/bin/python3


def validUTF8(data):
    """Checks if the data is valid UTF-8."""
    num_bytes = 0
    for n in data:
        mask = 1 << 7
        if not num_bytes:
            while mask & n:
                num_bytes += 1
                mask >>= 1
            if not num_bytes:
                continue
            if num_bytes == 1 or num_bytes > 4:
                return False
        else:
            if n >> 6 != 0b10:
                return False
        num_bytes -= 1
    return num_bytes == 0
