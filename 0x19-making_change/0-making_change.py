#!/usr/bin/python3
"""Provides makeChange()."""


def makeChange(coins, total):
    """
    Determines the fewest number of coins needed to reach the total.
    """
    if total <= 0:
        return 0
    dp = [0] + [float("inf")] * (total)
    for coin in coins:
        for i in range(coin, total + 1):
            dp[i] = min(dp[i], dp[i - coin] + 1)
    return dp[-1] if dp[-1] != float("inf") else -1
