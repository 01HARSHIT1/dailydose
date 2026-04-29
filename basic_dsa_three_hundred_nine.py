"""
Basic DSA - Best Time to Buy and Sell Stock with Transaction Fee
You may complete as many transactions as you like, but each sale pays a transaction fee.
Return the maximum profit.
"""


def max_profit_with_fee(prices, fee):
    """
    DP with 2 states:
    hold: max profit while holding stock
    cash: max profit while not holding stock
    Time Complexity: O(n)
    Space Complexity: O(1)
    """
    if not prices:
        return 0

    hold = -prices[0]
    cash = 0

    for p in prices[1:]:
        prev_cash = cash
        cash = max(cash, hold + p - fee)
        hold = max(hold, prev_cash - p)

    return cash


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Best Time to Buy and Sell Stock with Transaction Fee")
    print("=" * 60)

    print(max_profit_with_fee([1, 3, 2, 8, 4, 9], 2))  # 8
    print(max_profit_with_fee([1, 3, 7, 5, 10, 3], 3))  # 6
