"""
Basic DSA - Hamming Distance
Return the number of positions at which the corresponding bits of two integers differ.
"""


def hamming_distance(x, y):
    """
    XOR then count set bits.
    Time Complexity: O(1) for fixed word size (32 bits here)
    Space Complexity: O(1)
    """
    xor = x ^ y
    count = 0
    while xor:
        count += xor & 1
        xor >>= 1
    return count


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Hamming Distance")
    print("=" * 60)

    tests = [
        (1, 4, 2),
        (3, 1, 1),
        (0, 0, 0),
        (2**31 - 1, 0, 31),
    ]

    for x, y, expected in tests:
        got = hamming_distance(x, y)
        print(f"x={x}, y={y} -> {got} (expected {expected})")
