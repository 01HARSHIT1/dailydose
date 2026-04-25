"""
Basic DSA - Single Number II
Given an integer array nums where every element appears three times except for one,
which appears exactly once, return the single one.
"""


def single_number_ii(nums):
    """
    Bit counting across 32 bits, modulo 3.
    Time Complexity: O(32 * n)
    Space Complexity: O(1)
    """
    res = 0
    for b in range(32):
        mask = 1 << b
        cnt = 0
        for x in nums:
            if x & mask:
                cnt += 1
        if cnt % 3:
            res |= mask

    # convert to signed 32-bit integer if needed
    if res >= 2**31:
        res -= 2**32
    return res


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Single Number II")
    print("=" * 60)

    print(single_number_ii([2, 2, 3, 2]))  # 3
    print(single_number_ii([0, 1, 0, 1, 0, 1, 99]))  # 99
