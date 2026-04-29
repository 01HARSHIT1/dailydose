"""
Basic DSA - Best Time to Buy and Sell Stock with Cooldown
You may complete as many transactions as you like, but after you sell stock,
you cannot buy stock on the next day (cooldown 1 day).
Return the maximum profit.
"""


def max_profit_with_cooldown(prices):
    """
    DP with 3 states:
    hold: max profit while holding a stock
    sold: max profit just sold today
    rest: max profit in cooldown/rest state
    Time Complexity: O(n)
    Space Complexity: O(1)
    """
    if not prices:
        return 0

    hold = -prices[0]
    sold = 0
    rest = 0

    for p in prices[1:]:
        prev_sold = sold
        sold = hold + p
        hold = max(hold, rest - p)
        rest = max(rest, prev_sold)

    return max(sold, rest)


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Best Time to Buy and Sell Stock with Cooldown")
    print("=" * 60)

    print(max_profit_with_cooldown([1, 2, 3, 0, 2]))  # 3
    print(max_profit_with_cooldown([1]))  # 0
