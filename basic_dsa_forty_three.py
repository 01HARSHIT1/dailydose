"""
Basic DSA - Best Time to Buy and Sell Stock
Given prices where prices[i] is the price on day i, find the maximum profit from one buy and one sell.
"""


def max_profit(prices):
    """
    Track minimum price so far and best profit.
    Time Complexity: O(n)
    Space Complexity: O(1)
    """
    if not prices:
        return 0

    min_price = prices[0]
    best = 0

    for p in prices[1:]:
        if p < min_price:
            min_price = p
        else:
            best = max(best, p - min_price)

    return best


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Best Time to Buy and Sell Stock")
    print("=" * 60)

    tests = [
        ([7, 1, 5, 3, 6, 4], 5),
        ([7, 6, 4, 3, 1], 0),
        ([1, 2], 1),
        ([2, 1], 0),
        ([3, 3, 5, 0, 0, 3, 1, 4], 4),
        ([], 0),
    ]

    for prices, expected in tests:
        got = max_profit(prices)
        print(f"prices={prices} -> {got} (expected {expected})")

