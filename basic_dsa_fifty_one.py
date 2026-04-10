"""
Basic DSA - Plus One
Given a non-empty array of digits representing a non-negative integer (most significant digit first),
increment the integer by one and return the resulting digits.
"""


def plus_one(digits):
    """
    Simulate carry from the right.
    Time Complexity: O(n)
    Space Complexity: O(1) excluding output (worst case O(n) if new leading digit)
    """
    n = len(digits)
    for i in range(n - 1, -1, -1):
        if digits[i] < 9:
            digits[i] += 1
            return digits
        digits[i] = 0
    return [1] + digits


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Plus One")
    print("=" * 60)

    tests = [
        ([1, 2, 3], [1, 2, 4]),
        ([4, 3, 2, 1], [4, 3, 2, 2]),
        ([9], [1, 0]),
        ([9, 9, 9], [1, 0, 0, 0]),
        ([0], [1]),
    ]

    for d, expected in tests:
        original = d[:]
        got = plus_one(d)
        print(f"digits={original} -> {got} (expected {expected})")
