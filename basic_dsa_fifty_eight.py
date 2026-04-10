"""
Basic DSA - Power of Two
Return True if n is a power of two (n == 2^k for some non-negative integer k).
"""


def is_power_of_two(n):
    """
    Powers of two have exactly one bit set (n > 0 and n & (n - 1) == 0).
    Time Complexity: O(1)
    Space Complexity: O(1)
    """
    return n > 0 and (n & (n - 1)) == 0


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Power of Two")
    print("=" * 60)

    tests = [
        (1, True),
        (16, True),
        (3, False),
        (0, False),
        (-16, False),
        (1024, True),
    ]

    for n, expected in tests:
        got = is_power_of_two(n)
        print(f"n={n} -> {got} (expected {expected})")
