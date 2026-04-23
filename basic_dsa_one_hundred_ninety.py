"""
Basic DSA - Best Time to Buy and Sell Stock II
You may complete as many transactions as you like (buy one and sell one share
multiple times), but you must sell before you buy again.
Return the maximum profit.
"""


def max_profit_ii(prices):
    """
    Greedy: sum all positive price differences.
    Time Complexity: O(n)
    Space Complexity: O(1)
    """
    profit = 0
    for i in range(1, len(prices)):
        if prices[i] > prices[i - 1]:
            profit += prices[i] - prices[i - 1]
    return profit


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Best Time to Buy and Sell Stock II")
    print("=" * 60)

    print(max_profit_ii([7, 1, 5, 3, 6, 4]))  # 7
    print(max_profit_ii([1, 2, 3, 4, 5]))  # 4
    print(max_profit_ii([7, 6, 4, 3, 1]))  # 0
