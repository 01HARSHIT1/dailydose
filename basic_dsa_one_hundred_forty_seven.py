"""
Basic DSA - Best Time to Buy and Sell Stock
You are given prices where prices[i] is the price on day i.
Return the maximum profit you can achieve from one buy and one sell.
If you cannot achieve any profit, return 0.
"""


def max_profit(prices):
    """
    Track the minimum price so far and best profit so far.
    Time Complexity: O(n)
    Space Complexity: O(1)
    """
    min_price = float("inf")
    best = 0
    for p in prices:
        if p < min_price:
            min_price = p
        else:
            best = max(best, p - min_price)
    return best


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Best Time to Buy and Sell Stock")
    print("=" * 60)

    print(max_profit([7, 1, 5, 3, 6, 4]))  # 5
    print(max_profit([7, 6, 4, 3, 1]))  # 0
