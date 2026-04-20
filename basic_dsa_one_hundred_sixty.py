"""
Basic DSA - Reverse Bits
Reverse bits of a given 32-bit unsigned integer.
"""


def reverse_bits(n):
    """
    Build result bit-by-bit.
    Time Complexity: O(32)
    Space Complexity: O(1)
    """
    res = 0
    for _ in range(32):
        res = (res << 1) | (n & 1)
        n >>= 1
    return res


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Reverse Bits")
    print("=" * 60)

    # Example: 43261596 (00000010100101000001111010011100) -> 964176192
    print(reverse_bits(43261596))  # 964176192
