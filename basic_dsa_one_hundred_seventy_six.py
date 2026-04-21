"""
Basic DSA - Daily Temperatures
Given an array of integers temperatures, return an array answer such that answer[i]
is the number of days you have to wait after the i-th day to get a warmer temperature.
If there is no future day for which this is possible, keep answer[i] == 0.
"""


def daily_temperatures(temperatures):
    """
    Monotonic decreasing stack of indices.
    Time Complexity: O(n)
    Space Complexity: O(n)
    """
    n = len(temperatures)
    ans = [0] * n
    stack = []
    for i, t in enumerate(temperatures):
        while stack and temperatures[stack[-1]] < t:
            j = stack.pop()
            ans[j] = i - j
        stack.append(i)
    return ans


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Daily Temperatures")
    print("=" * 60)

    print(daily_temperatures([73, 74, 75, 71, 69, 72, 76, 73]))  # [1, 1, 4, 2, 1, 1, 0, 0]
    print(daily_temperatures([30, 40, 50, 60]))  # [1, 1, 1, 0]
