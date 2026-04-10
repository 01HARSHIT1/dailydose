"""
Basic DSA - Happy Number
A number is happy if repeatedly replacing it by the sum of the squares of its digits eventually reaches 1.
If it enters a cycle that does not include 1, it is not happy.
"""


def is_happy(n):
    """
    Floyd's cycle detection on the next-value function, or use a set.
    Here: set of seen sums (simple and clear).
    Time Complexity: O(log n) per step; bounded steps for 32-bit n
    Space Complexity: O(number of distinct sums in chain)
    """
    def next_num(x):
        total = 0
        while x:
            d = x % 10
            total += d * d
            x //= 10
        return total

    seen = set()
    while n != 1 and n not in seen:
        seen.add(n)
        n = next_num(n)
    return n == 1


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Happy Number")
    print("=" * 60)

    tests = [
        (19, True),
        (2, False),
        (1, True),
        (7, True),
        (4, False),
    ]

    for n, expected in tests:
        got = is_happy(n)
        print(f"n={n} -> {got} (expected {expected})")
