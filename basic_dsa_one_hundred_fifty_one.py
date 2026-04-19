"""
Basic DSA - Single Number
Given a non-empty array of integers nums, every element appears twice except for one.
Find that single one.
"""


def single_number(nums):
    """
    XOR cancels pairs: a^a = 0, and 0^b = b.
    Time Complexity: O(n)
    Space Complexity: O(1)
    """
    x = 0
    for v in nums:
        x ^= v
    return x


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Single Number")
    print("=" * 60)

    print(single_number([2, 2, 1]))  # 1
    print(single_number([4, 1, 2, 1, 2]))  # 4
