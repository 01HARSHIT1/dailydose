"""
Basic DSA - Missing Number
Given an array nums containing n distinct numbers in the range [0, n],
return the only number in the range that is missing from the array.
"""


def missing_number(nums):
    """
    XOR all indices 0..n with all values in nums; missing appears once.
    Time Complexity: O(n)
    Space Complexity: O(1)
    """
    x = 0
    for i, v in enumerate(nums):
        x ^= i ^ v
    x ^= len(nums)
    return x


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Missing Number")
    print("=" * 60)

    tests = [
        ([3, 0, 1], 2),
        ([0, 1], 2),
        ([9, 6, 4, 2, 3, 5, 7, 0, 1], 8),
        ([0], 1),
    ]

    for nums, expected in tests:
        got = missing_number(nums)
        print(f"nums={nums} -> {got} (expected {expected})")
