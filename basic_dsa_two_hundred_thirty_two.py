"""
Basic DSA - Coin Change
You are given an integer array coins representing coins of different denominations
and an integer amount representing a total amount of money.
Return the fewest number of coins needed to make up that amount. If it cannot be done,
return -1.
"""


def coin_change(coins, amount):
    """
    1D DP: dp[a] = min coins to make amount a.
    Time Complexity: O(amount * len(coins))
    Space Complexity: O(amount)
    """
    dp = [amount + 1] * (amount + 1)
    dp[0] = 0
    for a in range(1, amount + 1):
        best = amount + 1
        for c in coins:
            if c <= a:
                best = min(best, dp[a - c] + 1)
        dp[a] = best
    return -1 if dp[amount] > amount else dp[amount]


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Coin Change")
    print("=" * 60)

    print(coin_change([1, 2, 5], 11))  # 3
    print(coin_change([2], 3))  # -1
