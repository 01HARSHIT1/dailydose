"""
Basic DSA - Best Time to Buy and Sell Stock II
You may complete as many transactions as you like (buy then sell before buying again).
Return the maximum profit.
"""


def max_profit(prices):
    """
    Sum all positive day-to-day increases (greedy captures all uphill segments).
    Time Complexity: O(n)
    Space Complexity: O(1)
    """
    total = 0
    for i in range(1, len(prices)):
        if prices[i] > prices[i - 1]:
            total += prices[i] - prices[i - 1]
    return total


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Best Time to Buy and Sell Stock II")
    print("=" * 60)

    tests = [
        ([7, 1, 5, 3, 6, 4], 7),
        ([1, 2, 3, 4, 5], 4),
        ([7, 6, 4, 3, 1], 0),
        ([], 0),
    ]

    for prices, expected in tests:
        got = max_profit(prices)
        print(f"prices={prices} -> {got} (expected {expected})")
