"""
Basic DSA - Daily Temperatures
For each day, return how many days you must wait until a warmer temperature.
If there is no future day with a higher temperature, use 0 for that day.
"""


def daily_temperatures(temperatures):
    """
    Monotonic decreasing stack of indices.
    Time Complexity: O(n)
    Space Complexity: O(n)
    """
    n = len(temperatures)
    answer = [0] * n
    stack = []

    for i, t in enumerate(temperatures):
        while stack and temperatures[stack[-1]] < t:
            j = stack.pop()
            answer[j] = i - j
        stack.append(i)

    return answer


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Daily Temperatures")
    print("=" * 60)

    tests = [
        ([73, 74, 75, 71, 69, 72, 76, 73], [1, 1, 4, 2, 1, 1, 0, 0]),
        ([30, 40, 50, 60], [1, 1, 1, 0]),
        ([30, 60, 90], [1, 1, 0]),
    ]

    for temps, expected in tests:
        got = daily_temperatures(temps)
        print(f"temperatures={temps} -> {got} (expected {expected})")
