"""
Basic DSA - Number of 1 Bits (Hamming Weight)
Write a function that takes an unsigned integer and returns the number of '1' bits.
"""


def hamming_weight(n):
    """
    Brian Kernighan's trick: repeatedly clear the lowest set bit.
    Time Complexity: O(k) where k is number of set bits (<= 32)
    Space Complexity: O(1)
    """
    count = 0
    while n:
        n &= n - 1
        count += 1
    return count


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Number of 1 Bits (Hamming Weight)")
    print("=" * 60)

    print(hamming_weight(0b00000000000000000000000000001011))  # 3
    print(hamming_weight(0b00000000000000000000000010000000))  # 1
    print(hamming_weight(0b11111111111111111111111111111101))  # 31
