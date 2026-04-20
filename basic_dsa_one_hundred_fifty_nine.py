"""
Basic DSA - Counting Bits
Given an integer n, return an array ans of length n + 1 where ans[i] is the number
of 1's in the binary representation of i.
"""


def count_bits(n):
    """
    DP: bits[i] = bits[i >> 1] + (i & 1)
    Time Complexity: O(n)
    Space Complexity: O(n)
    """
    bits = [0] * (n + 1)
    for i in range(1, n + 1):
        bits[i] = bits[i >> 1] + (i & 1)
    return bits


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Counting Bits")
    print("=" * 60)

    print(count_bits(2))  # [0, 1, 1]
    print(count_bits(5))  # [0, 1, 1, 2, 1, 2]
